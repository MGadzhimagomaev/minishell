/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:22:14 by mgadzhim          #+#    #+#             */
/*   Updated: 2026/05/10 16:44:33 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strarr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	is_valid_path(char *path)
{
	return (access(path, F_OK | X_OK) == 0);
}

char	**get_path_dirs(char **env)
{
	char	*path;

	path = ft_getenv("PATH", env);
	if (!path)
		return (NULL);
	return (ft_split(path, ':'));
}

char	*check_in_dirs(char **dirs, char *name)
{
	char	*tmp;
	char	*full;
	int		i;

	i = 0;
	while (dirs[i])
	{
		tmp = ft_strjoin(dirs[i], "/");
		full = ft_strjoin(tmp, name);
		free(tmp);
		if (is_valid_path(full))
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

char	*resolve_path(char *name, char **env)
{
	char	**dirs;
	char	*path;

	if (!name)
		return (NULL);
	if (ft_strchr(name, '/'))
	{
		if (is_valid_path(name))
			return (ft_strdup(name));
		return (NULL);
	}
	dirs = get_path_dirs(env);
	if (!dirs)
		return (NULL);
	path = check_in_dirs(dirs, name);
	free_strarr(dirs);
	return (path);
}
