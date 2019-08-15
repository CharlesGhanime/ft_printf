/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_octal_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:47:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/15 13:53:41 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_generic(t_ptf *percents, char *base)
{
	char *str;
	int ret = 0;

	str = NULL;
	if (!(str = get_generic_var(percents, base)))
		return (FALSE);
//	printf("ITIZ == %s\n", str);
//	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str))))
//		return (FALSE);
	if (percents->options & !MINUS)
		ret = ft_handle_precision(percents, ft_strlen(str));
	if (percents->options & ZERO && percents->precision > percents->width)
		ft_write('0', percents->precision - ft_strlen(str));
	else if (percents->options & ZERO && percents->width > percents->precision)
		ft_write('0', percents->width - ft_strlen(str));
//	printf("ITIZ2 == %s\n", str);
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
//	printf("ITIZ3 == %s\n", str);
//	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
//		return (FALSE);
//	printf("ITIZ4 == %s\n", str);
	percents->size = ft_strlen(str);
	ft_putstr(str);
	if (percents->options & MINUS)
		ret = ft_handle_precision(percents, ft_strlen(str));
	if (str)
		free(str);
	return (TRUE);
}

/* PRINT OCTAL */

int		ft_print_octal(t_ptf *percents)
{
	char *str;
	char *base;

	str = NULL;
	base = "01234567";
	return (ft_print_generic(percents, base));
}

/* PRINT UNSIGNED */

int		ft_print_unsigned(t_ptf *percents)
{
	char *str;
	char *base;

	str = NULL;
	base = "0123456789";
	return (ft_print_generic(percents, base));
}

/* PRINT HEXA */

int		ft_print_hexa(t_ptf *percents)
{
	char *str;
	char *base;

	str = NULL;
	base = "0123456789abcdef";
	return (ft_print_generic(percents, base));
}

/* PRINT HEXA MAJ */

int		ft_print_hexa_maj(t_ptf *percents)
{
	char *str;
	char *base;

	str = NULL;
	base = "0123456789ABCDEF";
	return (ft_print_generic(percents, base));
}

/* PRINT FLOAT */

int		ft_print_float(t_ptf *percents)
{
	char *str;
	int i;

	i = 0;
	str = ft_ftoa(percents->a_t.a_ldouble);

	if (percents->precision <= 0)
		percents->precision = 6;
	if (percents->precision)
		if (str[percents->precision] > '5')
		{
			str[i] = '0';
			str[i - 1] += '1';
		}
	ft_strncat(str, "\0", percents->precision + 1);
	ft_putstr(str);
	return (TRUE);
}
