/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:59:33 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/18 18:27:54 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>

int	main()
{
	char	str[] = "tEsT ThIs";
	int	i = 0;

	printf("Before: %s\n", str);
	while (i < 9)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	printf("After: %s\n", str);
}//*/