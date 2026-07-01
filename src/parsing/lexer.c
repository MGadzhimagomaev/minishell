/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:30:11 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/07 20:14:55 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_token	*new_token(t_type type, char *value, int has_quote)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = type;
	tok->value = value;
	tok->has_quote = has_quote;
	tok->next = NULL;
	return (tok);
}

void	token_add_back(t_token **lst, t_token *tok)
{
	t_token	*cur;

	if (!*lst)
	{
		*lst = tok;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = tok;
}

t_token	*tokenize(char *line)
{
	t_token	*list;
	int		i;

	list = NULL;
	i = 0;
	while (line[i])
		lex_one(line, &i, &list);
	return (list);
}
