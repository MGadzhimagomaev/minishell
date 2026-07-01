/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:50:47 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:50:51 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_list *head = ft_lstnew("second");
    t_list *new_node = ft_lstnew("first");

    ft_lstadd_front(&head, new_node);

    printf("First node content: %s\n", (char *)head->content);
    printf("Second node content: %s\n", (char *)head->next->content);

    // free nodes manually for your test
    free(head->next);
    free(head);
}//*/
