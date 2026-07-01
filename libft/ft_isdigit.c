/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:10:40 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/15 19:16:59 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    char tests[] = {'0', '5', '9', 'a', ' '};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        printf("ft_isdigit('%c') = %d, isdigit('%c') = %d\n",
            tests[i], ft_isdigit(tests[i]),
            tests[i], isdigit(tests[i]));
    }
}//*/
