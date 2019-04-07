/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:08:07 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/07 10:09:58 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

p_func		ft_get_print_char()
{
	return (ft_print_char);
}

p_func		ft_get_print_string()
{
	return (ft_print_string);
}

p_func		ft_get_print_address()
{
	return (ft_print_address);
}

p_func		ft_get_print_decimal()
{
	return (ft_print_decimal);
}

p_func		ft_get_print_integer()
{
	return (ft_print_integer);
}
