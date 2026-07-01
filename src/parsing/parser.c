/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:02:55 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/13 18:55:04 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

int	parse_redir(t_token **tok, t_cmd *cmd)
{
	t_type		type;
	t_redir		*redir;

	type = (*tok)->type;
	*tok = (*tok)->next;
	if (!*tok || (*tok)->type != TOKEN_WORD)
		return (syntax_error("newline"));
	redir = new_redir(type, ft_strdup((*tok)->value));
	if (!redir)
		return (-1);
	redir->heredoc_fd = -1;
	cmd_add_redir(cmd, redir);
	*tok = (*tok)->next;
	return (0);
}

int	parse_word(t_token **tok, t_cmd *cmd)
{
	cmd_add_arg(cmd, ft_strdup((*tok)->value));
	*tok = (*tok)->next;
	return (0);
}

static int	fill_cmd(t_token **tok, t_cmd *cmd, t_shell *shell)
{
	while (*tok && (*tok)->type != TOKEN_PIPE)
	{
		if ((*tok)->type == TOKEN_WORD)
			parse_word(tok, cmd);
		else if (parse_redir(tok, cmd) == -1)
		{
			shell->exit_status = 2;
			return (-1);
		}
	}
	return (0);
}

t_cmd	*parse(t_token *tokens, t_shell *shell)
{
	t_cmd	*head;
	t_cmd	*tail;
	t_cmd	*cmd;
	t_token	*tok;

	if (leading_pipe(tokens, shell))
		return (NULL);
	head = NULL;
	tail = NULL;
	tok = tokens;
	while (tok)
	{
		cmd = new_cmd();
		if (!cmd || fill_cmd(&tok, cmd, shell) == -1)
			return (free_cmd(cmd), free_cmds_full(head), NULL);
		if (!head)
			head = cmd;
		else
			tail->next = cmd;
		tail = cmd;
		if (pipe_advance(&tok, head, shell) == -1)
			return (NULL);
	}
	return (head);
}
