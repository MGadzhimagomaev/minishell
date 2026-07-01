/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:58:44 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/09 17:42:19 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Reads inside a quote, returning content WITHOUT the quote chars.
   Used by heredoc delimiter detection and expand.c. */
char	*get_quoted(char *line, int *i, char quote)
{
	int		start;
	char	*part;

	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != quote)
		(*i)++;
	part = ft_substr(line, start, *i - start);
	if (line[*i] == quote)
		(*i)++;
	return (part);
}

/* Reads a non-quote, non-special run of characters. */
char	*get_word(char *line, int *i)
{
	int	start;

	start = *i;
	while (line[*i] && !is_whitespace(line[*i])
		&& !is_operator(line[*i]) && line[*i] != '|'
		&& line[*i] != '\'' && line[*i] != '"')
		(*i)++;
	return (ft_substr(line, start, *i - start));
}

t_type	get_redir_type(char *line, int *i)
{
	if (line[*i] == '<')
	{
		(*i)++;
		if (line[*i] == '<')
		{
			(*i)++;
			return (TOKEN_HEREDOC);
		}
		return (TOKEN_REDIR_IN);
	}
	(*i)++;
	if (line[*i] == '>')
	{
		(*i)++;
		return (TOKEN_APPEND);
	}
	return (TOKEN_REDIR_OUT);
}

int	check_quotes(char *line)
{
	int		i;
	char	quote;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
				i++;
			if (!line[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

/* Collects a full word token including raw quote chars so the expander
   can distinguish 'literal' from "expanded" from unquoted sections. */
char	*merge_word_parts(char *line, int *i, int *has_q)
{
	char	*result;
	char	quote;

	result = ft_strdup("");
	while (line[*i] && !is_whitespace(line[*i])
		&& line[*i] != '|' && !is_operator(line[*i]))
	{
		if (line[*i] == '\'' || line[*i] == '"')
		{
			*has_q = 1;
			quote = line[(*i)++];
			result = str_append_c(result, quote);
			while (line[*i] && line[*i] != quote)
				result = str_append_c(result, line[(*i)++]);
			if (line[*i])
				result = str_append_c(result, line[(*i)++]);
		}
		else
			result = str_append_c(result, line[(*i)++]);
	}
	return (result);
}
