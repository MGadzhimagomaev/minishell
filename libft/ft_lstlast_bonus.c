/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:55:55 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:55:56 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	lst->next = NULL;
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_list *head = ft_lstnew("first");
    ft_lstadd_back(&head, ft_lstnew("second"));
    ft_lstadd_back(&head, ft_lstnew("last"));

    t_list *last = ft_lstlast(head);
    if (last)
        printf("Last node content: %s\n", (char *)last->content);

    // free nodes manually
    while (head)
    {
        t_list *tmp = head->next;
        free(head);
        head = tmp;
    }
}//*/
