/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 09:15:30 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/05/17 14:55:12 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	delim_quoted(char *raw, char **clean)
{
	int		i;
	int		quoted;
	char	*result;

	i = 0;
	quoted = 0;
	result = ft_strdup("");
	while (raw[i])
	{
		if (raw[i] == '\'' || raw[i] == '"')
		{
			quoted = 1;
			result = str_append(result, get_quoted(raw, &i, raw[i]));
		}
		else
			result = str_append_c(result, raw[i++]);
	}
	*clean = result;
	return (quoted);
}

char	*expand_heredoc_line(char *line, t_shell *shell)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			tmp = expand_dollar(line, &i, shell);
			result = str_append(result, tmp);
			free(tmp);
		}
		else
			result = str_append_c(result, line[i++]);
	}
	return (result);
}

int	heredoc_loop(char *delim, int fd, t_shell *shell, int expand)
{
	char	*line;
	char	*expanded;

	heredoc_signals();
	while (1)
	{
		line = readline("> ");
		if (!line || g_signal == SIGINT)
			return (free(line), -1);
		if (ft_strncmp(line, delim, ft_strlen(delim) + 1) == 0)
		{
			free(line);
			break ;
		}
		if (expand)
			expanded = expand_heredoc_line(line, shell);
		else
			expanded = ft_strdup(line);
		write(fd, expanded, ft_strlen(expanded));
		write(fd, "\n", 1);
		free(line);
		free(expanded);
	}
	return (0);
}

int	heredoc(t_redir *redir, t_shell *shell)
{
	int		pipefd[2];
	char	*delim;
	int		expand;

	if (pipe(pipefd) == -1)
		return (-1);
	expand = !delim_quoted(redir->file, &delim);
	if (heredoc_loop(delim, pipefd[1], shell, expand) == -1)
	{
		free(delim);
		close(pipefd[0]);
		close(pipefd[1]);
		setup_signals(0);
		return (-1);
	}
	free(delim);
	close(pipefd[1]);
	redir->heredoc_fd = pipefd[0];
	setup_signals(0);
	return (0);
}

int	setup_heredocs(t_cmd *cmds, t_shell *shell)
{
	t_cmd	*cmd;
	t_redir	*redir;

	cmd = cmds;
	while (cmd)
	{
		redir = cmd->redirs;
		while (redir)
		{
			if (redir->type == TOKEN_HEREDOC)
			{
				if (heredoc(redir, shell) == -1)
				{
					shell->exit_status = 130;
					return (-1);
				}
			}
			redir = redir->next;
		}
		cmd = cmd->next;
	}
	return (0);
}
