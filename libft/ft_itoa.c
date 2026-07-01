/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:55:50 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/25 19:00:59 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	digit_count(int n)
{
	int	result;

	result = 1;
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		n *= -1;
		result++;
	}
	while (n >= 10)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*output;
	size_t	len;

	len = digit_count(n);
	if (n == -2147483648)
	{
		output = ft_strdup("-2147483648");
		return (output);
	}
	output = (char *)ft_calloc(len + 1, sizeof(char));
	if (!output)
		return (NULL);
	output[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		output[0] = '-';
	}
	while (n >= 10)
	{
		output[--len] = (n % 10) + '0';
		n /= 10;
	}
	output[len - 1] = n + '0';
	return (output);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = {1234, -5678, 0};
    for (int i = 0; i < 3; i++)
    {
        char *res = ft_itoa(nums[i]);
        printf("ft_itoa(%d) = %s\n", nums[i], res);
        free(res);
    }
}//*/
