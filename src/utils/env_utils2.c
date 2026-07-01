/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:05:33 by rmarkov           #+#    #+#             */
/*   Updated: 2026/05/02 09:17:44 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_env_entry(char *name, char *value)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(name, "=");
	if (!tmp)
		return (NULL);
	if (value)
		result = ft_strjoin(tmp, value);
	else
		result = ft_strdup(tmp);
	free(tmp);
	return (result);
}

char	**env_dup(char **env)
{
	char	**new;
	int		n;
	int		i;

	n = env_count(env);
	new = malloc(sizeof(char *) * (n + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new[i] = ft_strdup(env[i]);
		if (!new[i])
		{
			new[i] = NULL;
			free_strarr_n(new);
			return (NULL);
		}
		i++;
	}
	new[n] = NULL;
	return (new);
}

int	valid_identifier(char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*get_env_name(char *entry)
{
	int		len;
	char	*eq;

	eq = ft_strchr(entry, '=');
	if (!eq)
		return (ft_strdup(entry));
	len = eq - entry;
	return (ft_substr(entry, 0, len));
}

int	env_exists(char *name, char **env)
{
	int	i;
	int	len;

	if (!name || !env)
		return (0);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (1);
		i++;
	}
	return (0);
}
