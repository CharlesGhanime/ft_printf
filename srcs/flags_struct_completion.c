/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_struct_completion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:09:26 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/30 12:29:16 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_stock		*flags_struct_completion(t_stock *head, int flags, int field_width, int precision)
{
	t_stock *node;
	t_stock *tmp;

	node = flags_struct_creation();
	node->flags = flags;
	node->field_width = field_width;
	node->precision = precision;
	if (head == NULL)
		head = node;
	else
		tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = NULL;
	return (head);
}
