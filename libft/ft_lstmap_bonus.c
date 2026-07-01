/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:56:12 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 19:59:46 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!(new_node))
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *dup_content(void *content)
{
    return strdup((char *)content);
}

void del(void *content)
{
    free(content);
}

int main()
{
    t_list *head = ft_lstnew("one");
    ft_lstadd_back(&head, ft_lstnew("two"));
    ft_lstadd_back(&head, ft_lstnew("three"));
    t_list *new_list = ft_lstmap(head, dup_content, del);
    t_list *tmp = new_list;
    while (tmp)
    {
        printf("Mapped content: %s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    while (head)
    {
        t_list *tmp = head->next;
        free(head);
        head = tmp;
    }
    ft_lstclear(&new_list, del);
    return 0;
}//*/
