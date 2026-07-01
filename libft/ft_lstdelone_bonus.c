/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:58:00 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/06/01 18:58:15 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

void del(void *content)
{
    printf("Deleting content: %s\n", (char *)content);
    // no actual freeing of content since string literals, just example
}

int main()
{
    t_list *node = ft_lstnew("to delete");
    ft_lstdelone(node, del);
    // node memory freed inside ft_lstdelone

    return 0;
}//*/
