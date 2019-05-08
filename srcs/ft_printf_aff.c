/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:28:31 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/08 16:54:11 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list arg)
{
	char c;
	int nb;

	nb = 1;
	c = va_arg(arg, int);
	ft_putchar(c);
	return (TRUE);
}

int		ft_print_string(va_list arg)
{
	int nb;

	nb = ft_strlen(va_arg(arg, char *));
	ft_putstr(va_arg(arg, char *));
	return (TRUE);
}

int		ft_print_address(va_list arg)
{
	ft_putstr("0x");
	if (arg == NULL)
		ft_putchar('0');
	else
		ft_putstr(ft_itoa_base((long)va_arg(arg, int), 16));
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
