/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:34:40 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 19:14:20 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src && n > 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char std_buf[30] = "Overlapping copy test!";
	char std_buf_ft[30] = "Overlapping copy test!";
	char std_buf3[30] = "\0";
	char std_buf2[30] = "";
	char std_buf4[30] = "X";
	// char ft_buf[30] = "Overlapping copy test!";

	// Print before
	printf("Before:\n");
	printf("std_buf: %s\n", std_buf);
	// printf("ft_buf : %s\n", ft_buf);

	// Overlapping copy: copy 10 bytes from index 0 to index 5
	memmove(std_buf + 5, std_buf, 10);	
	ft_memmove(std_buf_ft + 5, std_buf_ft, 10);	
	printf("\nAfter 1:\n");
	printf("Orig: %s\n", std_buf);
	printf("ft_memmove: %s\n", std_buf_ft);
	// Compare memory
	if (memcmp(std_buf, std_buf_ft, sizeof(std_buf)) == 0)
		printf("\n✅ Buffers match! ft_memmove works correctly.\n");
	else
		printf("\n❌ Buffers do not match. Bug detected in ft_memmove.\n");

	memmove(std_buf + 5, std_buf2, 10);
	ft_memmove(std_buf_ft + 5, std_buf2, 10);	
	printf("\nAfter 2:\n");
	printf("Orig: %s\n", std_buf);
	printf("ft_memmove: %s\n", std_buf_ft);
	// Compare memory
	if (memcmp(std_buf, std_buf_ft, sizeof(std_buf)) == 0)
		printf("\n✅ Buffers match! ft_memmove works correctly.\n");
	else
		printf("\n❌ Buffers do not match. Bug detected in ft_memmove.\n");

	memmove(std_buf + 5, std_buf3, 10);
	ft_memmove(std_buf_ft + 5, std_buf3, 10);	
	printf("\nAfter 3:\n");
	printf("Orig: %s\n", std_buf);
	printf("ft_memmove: %s\n", std_buf_ft);
	// Compare memory
	if (memcmp(std_buf, std_buf_ft, sizeof(std_buf)) == 0)
		printf("\n✅ Buffers match! ft_memmove works correctly.\n");
	else
		printf("\n❌ Buffers do not match. Bug detected in ft_memmove.\n");

	memmove(std_buf + 5, std_buf4, 10);
	ft_memmove(std_buf_ft + 5, std_buf4, 10);	
	printf("\nAfter 4:\n");
	printf("Orig: %s\n", std_buf);
	printf("ft_memmove: %s\n", std_buf_ft);
	// Compare memory
	if (memcmp(std_buf, std_buf_ft, sizeof(std_buf)) == 0)
		printf("\n✅ Buffers match! ft_memmove works correctly.\n");
	else
		printf("\n❌ Buffers do not match. Bug detected in ft_memmove.\n");

	return 0;
}//*/