/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:17:35 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/18 20:43:07 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	output;

	i = 0;
	sign = 1;
	output = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		output = output * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * output);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char *nptr = "			  -3214562x";

	printf("Original val: %s\nAfter ft_atoi: %d\n", nptr, ft_atoi(nptr));
	printf("After atoi: %d\n", atoi(nptr));
}//*/