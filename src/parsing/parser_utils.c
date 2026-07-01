/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 09:44:22 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/06 13:20:17 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->args)
		return (0);
	while (cmd->args[i])
		i++;
	return (i);
}

void	cmd_add_arg(t_cmd *cmd, char *arg)
{
	char	**new;
	int		n;
	int		i;

	n = count_args(cmd);
	new = malloc(sizeof(char *) * (n + 2));
	if (!new)
		return ;
	i = 0;
	while (i < n)
	{
		new[i] = cmd->args[i];
		i++;
	}
	new[n] = arg;
	new[n + 1] = NULL;
	free(cmd->args);
	cmd->args = new;
}

t_redir	*new_redir(t_type type, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->file = file;
	redir->heredoc_fd = -1;
	redir->next = NULL;
	return (redir);
}

void	cmd_add_redir(t_cmd *cmd, t_redir *redir)
{
	t_redir	*cur;

	if (!cmd->redirs)
	{
		cmd->redirs = redir;
		return ;
	}
	cur = cmd->redirs;
	while (cur->next)
		cur = cur->next;
	cur->next = redir;
}

void	free_redir_node(t_redir *redir)
{
	if (!redir)
		return ;
	free(redir->file);
	if (redir->heredoc_fd > 0)
		close(redir->heredoc_fd);
	free(redir);
}
