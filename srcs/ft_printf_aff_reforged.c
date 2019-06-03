/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff_reforged.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:35:39 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/31 10:35:42 by cghanime         ###   ########.fr       */
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
            write(1, " ", (percents->width) - nb);
        }
        else
            ft_putchar(c);
    return (TRUE);
}

/* PRINT STRING */

int		ft_print_string(va_list arg, t_ptf *percents)
{
    unsigned long nb;
    char *starg;
    char *str;

    starg = va_arg(arg, char *);
    nb = ft_strlen(starg);
    str = (char *)malloc(sizeof(char) * nb + 1);
    ft_strncpy(str, starg, nb);
    ft_putstr(ft_width_precision(str, percents, nb));
    return (TRUE);
}

/* PRINT ADDRESS */

int		ft_print_address(va_list arg, t_ptf *percents)
{
    unsigned long nb;
    char *str;

    str = NULL;
    nb = ft_strlen(ft_itoa_base((long)va_arg(arg, int), 16));
    if (((percents->width) && !(percents->precision)) || ((percents->width) >= (percents->precision)))
    {
        if (nb > (percents->width))
        {
            {
                str = (char *)malloc(sizeof(char) * percents->width + 1);
                ft_strncpy(str, va_arg(arg,
                char *), (percents->width));
                ft_putstr("0x");
                ft_putstr(str);
            }
        }
    }
    if ((!((percents->width)) && ((percents->precision))) || ((percents->width) <= (percents->precision)))
    {
        if (nb > (percents->precision))
        {
            str = (char *)malloc(sizeof(char) * percents->precision + 1);
            ft_strncpy(str, va_arg(arg,
            char *), (percents->precision));
            ft_putstr("0x");
            ft_putstr(str);
        }
    }

    if (arg == NULL) {
        ft_putstr("0x");
        ft_putchar('0');
    }
    return (TRUE);
}

/* PRINT DECIMAL */

int		ft_print_decimal(va_list arg, t_ptf *percents)
{
    char *str;
    int nb;
    char c;

    c = va_arg(arg, int);
    nb = ft_strlen(ft_itoa(va_arg(arg, int)));
    str = (char *)malloc(sizeof(char) * nb + 1);
    str = ft_itoa(va_arg(arg, int));
    ft_putstr(ft_width_precision(str, percents, nb));
    return (TRUE);
}

/* PRINT INTEGER */

int		ft_print_integer(va_list arg, t_ptf *percents)
{
    char *str;
    int nb;

    nb = ft_strlen(ft_itoa(va_arg(arg, int)));
    str = (char *)malloc(sizeof(char) * nb + 1);
    str = ft_itoa(va_arg(arg, int));
    ft_putstr(ft_width_precision(str, percents, nb));
    return (TRUE);
}

/* PRINT OCTAL */

int		ft_print_octal(va_list arg, t_ptf *percents)
{
    unsigned long nb;
    char *str;

    nb = ft_strlen(ft_itoa(va_arg(arg, int)));
    str = (char *)malloc(sizeof(char) * nb + 1);
    str = ft_itoa_base(va_arg(arg, int), 8);
    ft_hashtag_flag(percents);
    ft_zero_flag(percents, nb);
    ft_putstr(str);
    ft_minus_flag(percents, nb);
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
    ft_hashtag_flag(percents);
    ft_zero_flag(percents, nb);
    ft_putstr(str);
    ft_minus_flag(percents, nb);
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
    ft_hashtag_flag(percents);
    ft_zero_flag(percents, nb);
    ft_putstr(str);
    ft_minus_flag(percents, nb);
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
    ft_putstr(ft_width_precision(str, percents, nb));
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