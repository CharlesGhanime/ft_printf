/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:08:07 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/28 01:59:57 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_pfunc		ft_get_print_char(void)
{
	return (ft_print_char);
}

t_pfunc		ft_get_print_string(void)
{
	return (ft_print_string);
}

t_pfunc		ft_get_print_address(void)
{
	return (ft_print_address);
}

t_pfunc		ft_get_print_decimal(void)
{
	return (ft_print_decimal);
}

t_pfunc		ft_get_print_integer(void)
{
	return (ft_print_decimal);
}
