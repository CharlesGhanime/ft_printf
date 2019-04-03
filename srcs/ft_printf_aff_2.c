/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:42:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/03 14:43:05 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_octal(va_list arg)
{
	ft_itoa_base(va_arg(arg, int), 8);
	return (true);
}

int		ft_print_unsigned(va_list arg)
{
	ft_itoa_base(va_arg(arg, int), 10);
	return (true);
}

int		ft_print_hexa(va_list arg)
{
	ft_itoa_base(va_arg(arg, int), 16);
	return (true);
}

int		ft_print_HEXA(va_list arg)
{
	ft_itoa_base(va_arg(arg, int), 16);
	return (true);
}
