/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:36:31 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/25 06:58:15 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nextlink;

	while (*alst)
	{
		nextlink = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = nextlink;
	}
	*alst = NULL;
}
