/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:30:55 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:50:23 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((!dest && !src) || (n == 0))
		return (dest);
	i = -1;
	while (++i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char std_buf[30] = "This is a test buffer!";
	char ft_buf[30] = "This is a test buffer!";

	// Print before
	printf("Before:\n");
	printf("std_buf: %s\n", std_buf);
	printf("ft_buf : %s\n", ft_buf);

	// Copy "test" over "This" (positions 0–3)
	memcpy(std_buf, std_buf + 10, 4);      // Copies "test"
	ft_memcpy(ft_buf, ft_buf + 10, 4);     // Your function does the same

	// Print after
	printf("\nAfter:\n");
	printf("std_buf: %s\n", std_buf);
	printf("ft_buf : %s\n", ft_buf);

	// Compare memory contents
	if (memcmp(std_buf, ft_buf, sizeof(std_buf)) == 0)
		printf("\n✅ Buffers match! ft_memcpy works correctly.\n");
	else
		printf("\n❌ Buffers do not match. There's a bug.\n");

	return 0;
}//*/