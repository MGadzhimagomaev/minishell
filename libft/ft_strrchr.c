/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:04:38 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 19:06:05 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence;

	last_occurence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occurence = (char *)s;
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (last_occurence);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "banana";

	printf("ft_strrchr: %s\n", ft_strrchr(s, 'a'));
	printf("strrchr:    %s\n", strrchr(s, 'a'));
}
//*/
