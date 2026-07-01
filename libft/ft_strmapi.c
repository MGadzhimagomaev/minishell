/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:02:40 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/25 19:25:36 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	output = ft_strdup(s);
	if (!output)
		return (NULL);
	while (output[i])
	{
		output[i] = f(i, output[i]);
		i++;
	}
	return (output);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *res = ft_strmapi("Hello 42!", ft_toupper);
    printf("ft_strmapi: %s\n", res);
    free(res);
}//*/
