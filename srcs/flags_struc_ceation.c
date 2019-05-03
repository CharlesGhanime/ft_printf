/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_struc_ceation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:56:57 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/03 11:58:27 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_stock		*flags_struct_creation()
{
	t_stock *head;

		if (!(head = (t_stock *)malloc(sizeof(t_stock))))
			return (NULL);
	head->flags = 0;
	head->fw = 0;
	head->p = 0;
	head->next = NULL;
	return (head);
}
