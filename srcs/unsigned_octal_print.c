/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_octal_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:47:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/30 15:22:24 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_octal(t_ptf *percents)
{
	char *base;

	base = "01234567";
	return (ft_print_generic(percents, base));
}

int		ft_print_unsigned(t_ptf *percents)
{
	char *base;

	base = "0123456789";
	return (ft_print_generic(percents, base));
}

int		ft_print_hexa(t_ptf *percents)
{
	char *base;

	base = "0123456789abcdef";
	return (ft_print_generic(percents, base));
}

int		ft_print_hexa_maj(t_ptf *percents)
{
	char *base;

	base = "0123456789ABCDEF";
	return (ft_print_generic(percents, base));
}

int		ft_print_float(t_ptf *percents)
{
	return (ft_print_float_generic(percents));
}
