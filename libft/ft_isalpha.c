/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:10:40 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/15 18:34:37 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
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
        printf("ft_isalpha('%c') = %d, isalpha('%c') = %d\n",
            tests[i], ft_isalpha(tests[i]),
            tests[i], isalpha(tests[i]));
    }
}//*/
