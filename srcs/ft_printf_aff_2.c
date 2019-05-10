/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:42:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/09 17:55:31 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* PRINT CHAR */

int		ft_print_octal(va_list arg, t_ptf *percents)
{
	ft_itoa_base(va_arg(arg, int), 8);
	return (TRUE);
}

/* PRINT CHAR */

int		ft_print_unsigned(va_list arg, t_ptf *percents)
{
	ft_itoa_base(va_arg(arg, int), 10);
	return (TRUE);
}

/* PRINT CHAR */

int		ft_print_hexa(va_list arg, t_ptf *percents)
{
	ft_putstr(ft_itoa_base(va_arg(arg, int), 16));
	return (TRUE);
}

/* PRINT CHAR */

int		ft_print_hexa_maj(va_list arg, t_ptf *percents)
{
    char *str;
    int i;

    str = ft_itoa_base(va_arg(arg, int), 16);
    i = 0;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    ft_printf("Test de mon hexa maj : %s", str);
	return (TRUE);
}

/* PRINT CHAR */

int		ft_print_float(va_list arg, t_ptf *percents)
{
	char *str;
	int i;

    i = 0;
	str = ft_ftoa(va_arg(arg, double));

	if (percents->precision)
		if (str[percents->precision] > 5 + '0')
		{
			str[i] = 0 + '0';
			str[i - 1] += 1 + '0';
		}
		ft_strncat(str, "\0", percents->precision + 1);

	ft_putstr(str);
	return (TRUE);
}
