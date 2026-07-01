/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:04 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:56:06 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int main()
{
    t_list *head = ft_lstnew("Node1");
    ft_lstadd_back(&head, ft_lstnew("Node2"));
    ft_lstadd_back(&head, ft_lstnew("Node3"));

    ft_lstiter(head, print_content);

    // free nodes manually for your test
    while (head)
    {
        t_list *tmp = head->next;
        free(head);
        head = tmp;
    }

    return 0;
}//*/
