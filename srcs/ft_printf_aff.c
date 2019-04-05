/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:28:31 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/05 09:15:56 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	ft_putchar(c);
	return (true);
}

int		ft_print_string(va_list arg)
{
	ft_putstr(va_arg(arg, char *));
	return (true);
}

int		ft_print_address(va_list arg)
{
	ft_itoa_base(va_arg(arg, int), 16);
	return (true);
}

int		ft_print_dec(va_list arg)
{
	ft_putnbr(va_arg(arg, int));
	return (true);
}

int		ft_print_int(va_list arg)
{
	ft_putnbr(va_arg(arg, int));
	return (true);
}
