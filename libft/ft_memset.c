/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:25:24 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/16 20:03:56 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)s)[--n] = (unsigned char)c;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main () 
{
	char str[50];
	char str2[50];

	strcpy(str, "Welcome to Tutorialspoint");
	puts(str);

	memset(str, '#', 7);
	puts(str);

	strcpy(str2, "Welcome to Tutorialspoint");
	puts(str2);

	ft_memset(str2, '#', 7);
	puts(str2);
	return(0);
}//*/