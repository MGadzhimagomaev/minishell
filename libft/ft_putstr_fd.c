/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:27:21 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/05/25 19:38:31 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
/*
#include <unistd.h>

int main()
{
    ft_putstr_fd("Test string for ft_putstr_fd\n", 1);
    ft_putstr_fd("", 1);  // empty string test
    ft_putstr_fd("Another line.\n", 1);
}//*/
