/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:00:00 by rmarkov           #+#    #+#             */
/*   Updated: 2026/06/29 12:00:00 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_error(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (token)
		ft_putstr_fd(token, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
	return (-1);
}

int	leading_pipe(t_token *tokens, t_shell *shell)
{
	if (tokens && tokens->type == TOKEN_PIPE)
	{
		syntax_error("|");
		shell->exit_status = 2;
		return (1);
	}
	return (0);
}

int	pipe_advance(t_token **tok, t_cmd *head, t_shell *shell)
{
	if (*tok && (*tok)->type == TOKEN_PIPE)
	{
		*tok = (*tok)->next;
		if (!*tok)
		{
			syntax_error("newline");
			shell->exit_status = 2;
			free_cmds_full(head);
			return (-1);
		}
	}
	return (0);
}
