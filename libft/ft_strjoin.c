/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:22:08 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/25 20:24:50 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len_pre;
	size_t	len_suff;

	len_pre = ft_strlen(s1);
	len_suff = ft_strlen(s2);
	output = (char *)ft_calloc(len_pre + len_suff + 1, sizeof(char));
	if (!output)
		return (NULL);
	ft_strlcpy(output, s1, len_pre + 1);
	ft_strlcpy(output + len_pre, s2, len_suff + 1);
	return (output);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "world!";

	printf("ft_strjoin: %s\n", ft_strjoin(s1, s2));
}
//*/
