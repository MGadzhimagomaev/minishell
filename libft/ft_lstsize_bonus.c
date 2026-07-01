/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:54:58 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:55:02 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst -> next;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_list *head = ft_lstnew("1");
    ft_lstadd_front(&head, ft_lstnew("0"));
    ft_lstadd_back(&head, ft_lstnew("2"));

    printf("List size: %d\n", ft_lstsize(head));

    // free nodes manually
    while (head)
    {
        t_list *tmp = head->next;
        free(head);
        head = tmp;
    }
}//*/
