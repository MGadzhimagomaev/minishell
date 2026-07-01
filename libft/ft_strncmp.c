/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:54:52 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/25 20:15:35 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
        const char      *a[4];
        const char      *b[4];
        char            *c[4];
        char            *d[4];

        *c = "ABJFCN"; 
        *d = "ABJFCJ";
        *a = *c;
        *b = *d;

        printf("%d\n",strncmp(a[0], b[0], 6));
        printf("%d",ft_strncmp(c[0], d[0], 6));
}//*/