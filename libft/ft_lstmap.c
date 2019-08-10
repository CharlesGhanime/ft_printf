/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:37:03 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/26 14:47:27 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlink;
	t_list	*link;

	if (!lst)
		return (NULL);
	link = f(lst);
	newlink = link;
	while (lst->next)
	{
		lst = lst->next;
		if (!(link->next = f(lst)))
		{
			free(link->next);
			return (NULL);
		}
		link = link->next;
	}
	return (newlink);
}
