/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:10:14 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/15 21:12:58 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    int tests[] = {65, 127, 128, -1, 0};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        printf("ft_isascii(%d) = %d, isascii(%d) = %d\n",
            tests[i], ft_isascii(tests[i]),
            tests[i], isascii(tests[i]));
    }
}//*/
