/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:28:31 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/09 17:54:45 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* PRINT CHAR */

int		ft_print_char(va_list arg, t_ptf *percents)
{
	char c;
	unsigned long nb;


    c = va_arg(arg, int);
	nb = 1;
	while (*(percents->options)++)
        if (*(percents->options) == '-' && (percents->width) > nb)
        {
            ft_putchar(c);
            write(1, " ", (percents->width) - 1);
        }
	    else
	        ft_putchar(c);
	return (TRUE);
}

/* PRINT STRING */

int		ft_print_string(va_list arg, t_ptf *percents)
{
	unsigned long nb;
	char *str;

	str = NULL;
	nb = ft_strlen(va_arg(arg, char *));

	if (((percents->width) && !(percents->precision)) || ((percents->width) >= (percents->precision))) {
        if (nb > (percents->width)) {
            ft_strncpy(str, va_arg(arg,
            char *), (percents->width));
            ft_putstr(str);
        }
    }
    if ((!((percents->width)) && ((percents->precision))) || ((percents->width) <= (percents->precision))) {
        if (nb > (percents->precision)) {
            ft_strncpy(str, va_arg(arg,
            char *), (percents->precision));
            ft_putstr(str);
        }
    }
    else {
        ft_putstr(va_arg(arg, char *));
    }

	return (TRUE);
}

/* PRINT ADDRESS */

int		ft_print_address(va_list arg, t_ptf *percents)
{
	ft_putstr("0x");
	if (arg == NULL)
		ft_putchar('0');
	else
		ft_putstr(ft_itoa_base((long)va_arg(arg, int), 16));
	return (TRUE);
}

/* PRINT DECIMAL */

int		ft_print_decimal(va_list arg, t_ptf *percents)
{
    unsigned long nb;

    nb = ft_strlen(ft_itoa(va_arg(arg, int)));
    while (*(percents->options++))
        if ((*(percents->options) != '-'))
        while (*(percents->options++))
            if (*(percents->options) == '0')
                ft_zero_flag(arg, percents, nb);
	ft_putnbr(va_arg(arg, int));
        if (*(percents->options) == '-')
            while (*(percents->options++)))
                if (*(percents->options) == '0')
                    ft_minus_flag(arg, percents, nb);
	return (TRUE);
}

/* PRINT INTEGER */

int		ft_print_integer(va_list arg, t_ptf *percents)
{
	ft_putnbr(va_arg(arg, int));
	return (TRUE);
}
