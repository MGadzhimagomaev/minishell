/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:18:40 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/14 15:30:22 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char	*str_append(char *dst, char *src)
{
	char	*result;

	if (!dst)
		dst = ft_strdup("");
	if (!src)
		return (dst);
	result = ft_strjoin(dst, src);
	free(dst);
	return (result);
}

char	*str_append_c(char *dst, char c)
{
	char	tmp[2];
	char	*result;

	tmp[0] = c;
	tmp[1] = '\0';
	if (!dst)
		dst = ft_strdup("");
	result = ft_strjoin(dst, tmp);
	free(dst);
	return (result);
}

char	*expand_dollar(char *str, int *i, t_shell *shell)
{
	char	*name;
	char	*val;

	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->exit_status));
	}
	if (!is_valid_var_char(str[*i]) && str[*i] != '?')
		return (ft_strdup("$"));
	name = get_var_name(str, i);
	val = get_var_value(name, shell);
	free(name);
	return (val);
}

void	expand_tokens(t_token *tokens, t_shell *shell)
{
	t_token	*tok;
	char	*expanded;
	int		prev_heredoc;

	tok = tokens;
	prev_heredoc = 0;
	while (tok)
	{
		if (tok->type == TOKEN_WORD && tok->value && !prev_heredoc)
		{
			expanded = expand_str(tok->value, shell);
			free(tok->value);
			tok->value = expanded;
		}
		prev_heredoc = (tok->type == TOKEN_HEREDOC);
		tok = tok->next;
	}
}
