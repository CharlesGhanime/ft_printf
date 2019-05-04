/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_struct_completion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:09:26 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/04 16:30:41 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_stock		*flags_struct_completion(t_stock *head, int flags, int fw, int pr)
{
	t_stock *node;
	t_stock *tmp;

	node = flags_struct_creation();
	node->flags = flags;
	node->fw = fw;
	node->pr = pr;
	if (head == NULL)
		head = node;
	else
		tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = NULL;
	return (head);
}
