/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:09:41 by aboitier          #+#    #+#             */
/*   Updated: 2019/06/24 23:11:40 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* PRINT CHAR */

int     ft_print_char(t_ptf *percents)
{
	percents->size = 1;
	ft_putchar((char)percents->a_t.a_int);
	return (TRUE);
}

/* PRINT STRING */

int     ft_print_string(t_ptf *percents)
{
	char *str;

	if (!(str = ft_strdup(percents->a_t.a_string)))
		return (FALSE);
	if (!(str = str_precision(str, percents->precision)))
		return (FALSE);
	if (!(str = str_width(str, percents->width, percents, ' ')))
		return (FALSE);
	ft_putstr(str);
//  printf(""_RED"%s"_END"", str);
	percents->size = ft_strlen(str);
	free(str);
	return (FALSE);
}

