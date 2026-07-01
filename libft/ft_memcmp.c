/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:24:06 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/18 19:42:19 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	const char *s1 = "abcdefgh";
	const char *s2 = "abcdefgi";
	int	n = 3;

	printf("ft_func: %d\n", ft_memcmp(s1, s2, n));
	printf("orig_func: %d\n", memcmp(s1, s2, n));
}//*/