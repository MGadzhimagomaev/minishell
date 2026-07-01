/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:01:17 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/21 20:39:59 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_ln;
	size_t	src_ln;
	size_t	i;

	dest_ln = ft_strlen(dest);
	src_ln = ft_strlen(src);
	i = 0;
	if (size <= dest_ln)
		return (size + src_ln);
	while (src[i] && (dest_ln + i) < size - 1)
	{
		dest[dest_ln + i] = src[i];
		i++;
	}
	dest[dest_ln + i] = '\0';
	return (dest_ln + src_ln);
}
/*
#include <stdio.h>

int main(void)
{
	char src[] = "Hello";
	char dest1[] = "Say: ";

	size_t r1 = ft_strlcat(dest1, src, 8);

	printf("ft_strlcat: %s (len: %zu)\n", dest1, r1);

	return 0;
}//*/