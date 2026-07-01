/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:22:47 by rmarkov           #+#    #+#             */
/*   Updated: 2026/04/29 16:05:18 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_count(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

char	*ft_getenv(char *name, char **env)
{
	int	i;
	int	len;

	if (!name || !env)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	env_set(char **env, char *name, char *value)
{
	int		i;
	int		len;
	char	*entry;

	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			entry = make_env_entry(name, value);
			if (!entry)
				return (0);
			free(env[i]);
			env[i] = entry;
			return (1);
		}
		i++;
	}
	return (0);
}

char	**env_add(char **env, char *entry)
{
	char	**new;
	int		n;
	int		i;

	n = env_count(env);
	new = malloc(sizeof(char *) * (n + 2));
	if (!new)
		return (env);
	i = 0;
	while (i < n)
	{
		new[i] = env[i];
		i++;
	}
	new[n] = entry;
	new[n + 1] = NULL;
	free(env);
	return (new);
}

char	**env_remove(char **env, char *name)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(name);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			free(env[i]);
			i++;
			continue ;
		}
		env[j++] = env[i++];
	}
	env[j] = NULL;
	return (env);
}
