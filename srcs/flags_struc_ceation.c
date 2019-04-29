/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_struc_ceation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:56:57 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/29 16:40:46 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_stock		*flags_struct_creation(t_stock *head)
{
	if(!(head = (t_stock *)malloc(sizeof(t_stock))))
		return (NULL);
	if (!head)
	{
		head->flags = 0;
		head->field_width = 0;
		head->precision = 0;
	}
	else
	{
		head->flags = flags;
		head->field_width = field_width;
		head->precision = precision;
	}
}
