/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:36 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:57:09 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!*lst || !del || !lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = temp;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

void del(void *content)
{
    printf("Deleting content: %s\n", (char *)content);
    // no actual freeing needed for literals
}

int main()
{
    t_list *head = ft_lstnew("1");
    ft_lstadd_back(&head, ft_lstnew("2"));
    ft_lstadd_back(&head, ft_lstnew("3"));

    ft_lstclear(&head, del);
    printf("List after clear: %p\n", (void *)head); // should print (nil)

    return 0;
}//*/
