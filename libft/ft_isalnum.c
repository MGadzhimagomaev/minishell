/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:58:43 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/15 21:05:43 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    char tests[] = {'a', 'Z', '5', '*', ' '};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        printf("ft_isalnum('%c') = %d, isalnum('%c') = %d\n",
            tests[i], ft_isalnum(tests[i]),
            tests[i], isalnum(tests[i]));
    }
}//*/
