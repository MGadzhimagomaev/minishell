/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:55:10 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:55:31 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_list *node = ft_lstnew("Hello");
    if (node)
    {
        printf("node->content = %s\n", (char *)node->content);
        free(node);
    }
    else
        printf("ft_lstnew returned NULL\n");
}//*/
