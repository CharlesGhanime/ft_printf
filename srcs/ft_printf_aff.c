/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:28:31 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/03 12:16:57 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
//	flag -
/*	if (flags << 6)
		if (flags << 3)
			write(1, '0', width - length)*/
//	flag +
	/*if (!flags << 5 && va_arg(arg, int) >= 0)
		ft_putchar(' ');*/
	ft_putchar(c);
	return (TRUE);
}

int		ft_print_string(va_list arg)
{
	ft_putstr(va_arg(arg, char *));
	return (TRUE);
}

int		ft_print_address(va_list arg)
{
	ft_itoa_base(va_arg(arg, unsigned int), 16);
	return (TRUE);
}

int		ft_print_decimal(va_list arg)
{
	ft_putnbr(va_arg(arg, int));
	return (TRUE);
}

int		ft_print_integer(va_list arg)
{
	ft_putnbr(va_arg(arg, int));
	return (TRUE);
}
