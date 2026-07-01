/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:46:13 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/19 22:31:30 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*output;

	if (size != 0 && nmemb != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	output = (void *)malloc(nmemb * size);
	if (!output)
		return (NULL);
	ft_bzero(output, nmemb * size);
	return (output);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *mem = ft_calloc(5, sizeof(char));

	if (mem)
	{
		for (int i = 0; i < 5; i++)
			printf("%d ", mem[i]);
		printf("\n");
		free(mem);
	}
}
//*/
