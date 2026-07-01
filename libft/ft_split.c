/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:57:35 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 19:52:21 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && ((s[i - 1] == c) || (i == 0)))
			count++;
		i++;
	}
	return (count);
}

static void	free_mem(char	**str, size_t	n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free (str[i++]);
	}
	free(str);
}

static int	ft_fill_array(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	element;

	i = 0;
	start = 0;
	element = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[element++] = ft_substr(s, start, i - start);
			if (!(arr[element - 1]))
				return (free_mem(arr, element - 1), 0);
		}
	}
	arr[element] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_fill_array(arr, s, c))
		return (NULL);
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char **out = ft_split("a b  c", ' ');

	for (int i = 0; out[i]; i++)
		printf("Word %d: %s\n", i, out[i]);
}
//*/
