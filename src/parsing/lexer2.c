/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:00:00 by rmarkov           #+#    #+#             */
/*   Updated: 2026/06/29 12:00:00 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*make_op_token(char *line, int *i)
{
	t_type	type;

	type = get_redir_type(line, i);
	return (new_token(type, NULL, 0));
}

void	lex_one(char *line, int *i, t_token **list)
{
	t_token	*tok;
	char	*word;
	int		has_q;

	if (is_whitespace(line[*i]))
		(*i)++;
	else if (line[*i] == '|')
	{
		(*i)++;
		token_add_back(list, new_token(TOKEN_PIPE, NULL, 0));
	}
	else if (is_operator(line[*i]))
		token_add_back(list, make_op_token(line, i));
	else
	{
		has_q = 0;
		word = merge_word_parts(line, i, &has_q);
		tok = new_token(TOKEN_WORD, word, has_q);
		token_add_back(list, tok);
	}
}
