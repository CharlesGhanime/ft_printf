/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:42:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/11 20:16:01 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* PRINT OCTAL */

int		ft_print_octal(va_list arg, t_ptf *percents)
{
    unsigned long nb;
    char *str;

    nb = ft_strlen(ft_itoa(va_arg(arg, int)));
	str = (char *)malloc(sizeof(char) * nb + 1);
    str = ft_itoa_base(va_arg(arg, int), 8);
    ft_hashtag_flag(arg, percents);
    ft_zero_flag(arg, percents, nb);
	ft_putstr(str);
    ft_minus_flag(arg, percents, nb);
    return (TRUE);
}

/* PRINT UNSIGNED */

int		ft_print_unsigned(va_list arg, t_ptf *percents)
{
    unsigned long nb;
    char *str;

    nb = ft_strlen(ft_itoa(va_arg(arg, int)));
    str = (char *)malloc(sizeof(char) * nb + 1);
	str = ft_itoa_base(va_arg(arg, int), 10);
	ft_hashtag_flag(arg, percents);
    ft_zero_flag(arg, percents, nb);
    ft_putstr(str);
    ft_minus_flag(arg, percents, nb);
	return (TRUE);
}

/* PRINT HEXA */

int		ft_print_hexa(va_list arg, t_ptf *percents)
{
    unsigned long nb;
    char *str;

    nb = ft_strlen(ft_itoa(va_arg(arg, int)));
    str = (char *)malloc(sizeof(char) * nb + 1);
	str = ft_itoa_base(va_arg(arg, int), 16);
    ft_hashtag_flag(arg, percents);
    ft_zero_flag(arg, percents, nb);
    ft_putstr(str);
    ft_minus_flag(arg, percents, nb);
	return (TRUE);
}

/* PRINT HEXA MAJ */

int		ft_print_hexa_maj(va_list arg, t_ptf *percents)
{
    char *str;
    int i;
    int nb;

    nb = ft_strlen(ft_itoa_base(va_arg(arg, int), 16));
    str = (char *)malloc(sizeof(char) * nb + 1);
    str = ft_itoa_base(va_arg(arg, int), 16);
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    ft_putstr(ft_width_precision(arg, percents, nb, str));
	return (TRUE);
}

/* PRINT FLOAT */

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
