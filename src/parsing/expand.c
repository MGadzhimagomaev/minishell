/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:33:08 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/12 10:44:55 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(char *str, int *i)
{
	int	start;

	start = *i;
	while (str[*i] && is_valid_var_char(str[*i]))
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

char	*get_var_value(char *name, t_shell *shell)
{
	char	*val;

	val = ft_getenv(name, shell->env);
	if (!val)
		return (ft_strdup(""));
	return (ft_strdup(val));
}

char	*expand_squote(char *str, int *i)
{
	int		start;
	char	*part;

	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	part = ft_substr(str, start, *i - start);
	if (str[*i] == '\'')
		(*i)++;
	return (part);
}

char	*expand_dquote(char *str, int *i, t_shell *shell)
{
	char	*result;
	char	*tmp;

	(*i)++;
	result = ft_strdup("");
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '$')
		{
			tmp = expand_dollar(str, i, shell);
			result = str_append(result, tmp);
			free(tmp);
		}
		else
			result = str_append_c(result, str[(*i)++]);
	}
	if (str[*i] == '"')
		(*i)++;
	return (result);
}

char	*expand_str(char *str, t_shell *shell)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			tmp = expand_squote(str, &i);
		else if (str[i] == '"')
			tmp = expand_dquote(str, &i, shell);
		else if (str[i] == '$')
			tmp = expand_dollar(str, &i, shell);
		else
		{
			result = str_append_c(result, str[i++]);
			continue ;
		}
		result = str_append(result, tmp);
		free(tmp);
	}
	return (result);
}
