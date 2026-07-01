/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:04:46 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/18 18:01:53 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)s)[--n] = '\0';
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char std_buf[20] = "Hello, 42 Berlin!";
	char ft_buf[20] = "Hello, 42 Berlin!";

	printf("Before:\n");
	printf("std_buf: %s\n", std_buf);
	printf("ft_buf : %s\n", ft_buf);

	bzero(std_buf + 7, 6);
	ft_bzero(ft_buf + 7, 6);

	printf("\nAfter:\n");
	printf("std_buf: %s\n", std_buf);
	printf("ft_buf : %s\n", ft_buf);

	// Check memory match
	if (memcmp(std_buf, ft_buf, 20) == 0)
		printf("\n✅ Buffers match! ft_bzero works correctly.\n");
	else
		printf("\n❌ Buffers do not match. Something is wrong.\n");

	return (0);
}//*/
