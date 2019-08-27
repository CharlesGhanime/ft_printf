/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ptr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:44:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/27 23:45:56 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_pfunc		ft_get_print_octal(void)
{
	return (ft_print_octal);
}

t_pfunc		ft_get_print_unsigned(void)
{
	return (ft_print_unsigned);
}

t_pfunc		ft_get_print_hexa(void)
{
	return (ft_print_hexa);
}

t_pfunc		ft_get_print_hexa_maj(void)
{
	return (ft_print_hexa_maj);
}

t_pfunc		ft_get_print_float(void)
{
	return (ft_print_float);
}
