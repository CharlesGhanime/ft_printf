/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_octal_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:47:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/16 15:04:36 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_generic(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = get_generic_var(percents, base)))
		return (FALSE);
	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str))))
		return (FALSE);
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
		return (FALSE);
	percents->size = ft_strlen(str);
	ft_putstr(str);
//	if (str)
//		free(str);
	return (TRUE);
}

int		ft_print_float_generic(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (!percents->precision)
		percents->precision = 6;
	if (!(str = get_float_generic_var(percents)))
		return (FALSE);
	if (!(str = float_prec_flag(str, percents->precision)))
		return (FALSE);
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
		return (FALSE);
	percents->size = ft_strlen(str);
	ft_putstr(str);
//	if (str)
//		free(str);
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
	
	str = NULL;
	return (ft_print_float_generic(percents));
}
