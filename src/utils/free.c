/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:44:01 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/05/19 17:22:08 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strarr_n(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_redir_list(t_redir *redir)
{
	t_redir	*next;

	while (redir)
	{
		next = redir->next;
		free(redir->file);
		if (redir->heredoc_fd > 0)
			close(redir->heredoc_fd);
		free(redir);
		redir = next;
	}
}

void	free_cmds_full(t_cmd *cmds)
{
	t_cmd	*next;

	while (cmds)
	{
		next = cmds->next;
		free_strarr_n(cmds->args);
		free_redir_list(cmds->redirs);
		free(cmds);
		cmds = next;
	}
}

void	free_token_list(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = next;
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_strarr_n(cmd->args);
	free_redir_list(cmd->redirs);
	free(cmd);
}
