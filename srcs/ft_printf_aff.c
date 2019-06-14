/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:28:31 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/14 16:40:21 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO : liste exhaustive des options s'appliquant a chaque type de conversion :
 *  utiliser uintmax_t ou intmax_t au lieu de unsigned int et int.
 *  CHAR : - + 0 espace hh et l (wint_t)
 *  STRING : hh et l (wchar_t *)
 *  ADDRESS : ??
 *  DECIMAL : - + 0 espace h, l et ll
 *  INTEGER : - + 0 espace h, l et ll
 *  OCTAL : - # 0 h, l et ll
 *  UNSIGNED : - # 0 h, l et ll
 *  HEXA : - # 0 h, l et ll
 *  HEXA_MAJ : - # 0 h, l et ll
 *  FLOAT : - + # 0 espace h, l et ll */

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

    ft_putstr(ft_width_precision(arg, percents, nb, str));
	/* TODO : fonction de gestion de la largeur de champs et de la precision
	 *  elle est a réutiliser dans les autres fonctions d'affichage */
/*
	if (((percents->width) && !(percents->precision)) || ((percents->width) >= (percents->precision)))
	{
        if (nb > (percents->width))
        {
            {
                str = (char *)malloc(sizeof(char) * percents->width + 1);
                ft_strncpy(str, va_arg(arg,
                char *), (percents->width));
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
            ft_putstr(str);
        }
    }
    else {
        ft_putstr(va_arg(arg, char *));
    }
*/
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
    unsigned long nb;

    nb = ft_strlen(ft_itoa(va_arg(arg, int)));


/*    while (*(percents->options++))
        if ((*(percents->options) != '-'))
        while (*(percents->options++))
            if (*(percents->options) == '0')
                ft_zero_flag(arg, percents, nb);
	ft_putnbr(va_arg(arg, int));
        if (*(percents->options) == '-')
            while (*(percents->options++))
                if (*(percents->options) == '0')
                    ft_minus_flag(arg, percents, nb); */
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
    ft_putstr(ft_width_precision(arg, percents, nb, str));
	return (TRUE);
}
