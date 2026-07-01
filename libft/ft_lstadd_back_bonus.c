/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:57:30 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:57:54 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_list *head = ft_lstnew("start");
    ft_lstadd_back(&head, ft_lstnew("middle"));
    ft_lstadd_back(&head, ft_lstnew("end"));

    t_list *tmp = head;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    // free nodes manually
    while (head)
    {
        t_list *next = head->next;
        free(head);
        head = next;
    }
}//*/
