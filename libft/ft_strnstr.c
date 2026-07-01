/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:50:28 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/25 20:19:56 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (j < little_len && big[i + j] == little[j] && j < len - i)
			j++;
		if (j == little_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	const char *largestring = "Foo Bar Ba";
	const char *smallstring = "Bar";
	size_t		x = 10;

	printf("ft_func: %s", ft_strnstr(largestring, smallstring, x));
	// printf("orig_func: %s", strnstr(largestring, smallstring, x));
}//*/