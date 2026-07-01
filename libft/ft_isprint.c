/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:10:14 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/23 21:24:26 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    char tests[] = {' ', 'A', '~', '\n', 127};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        printf("ft_isprint('%c' (code %d)) = %d, isprint('%c' (code %d)) = %d\n",
            (tests[i] >= 32 && tests[i] <= 126) ? tests[i] : ' ',
            tests[i], ft_isprint(tests[i]),
            (tests[i] >= 32 && tests[i] <= 126) ? tests[i] : ' ',
            tests[i], isprint(tests[i]));
    }
}//*/
