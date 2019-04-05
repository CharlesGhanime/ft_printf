/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:44:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/05 14:47:17 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

p_func		ft_get_print_octal()
{
	return (ft_print_octal);
}

p_func		ft_get_print_unsigned()
{
	return (ft_print_unsigned);
}

p_func		ft_get_print_hexa()
{
	return (ft_print_hexa);
}

p_func		ft_get_print_HEXA()
{
	return (ft_print_HEXA);
}
