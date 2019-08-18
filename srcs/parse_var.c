/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:37:51 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/18 18:04:59 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     get_type(t_ptf **word, va_list arg)
{
	if ((*word)->conv == 'c')
	{
		if (!((*word)->a_t.a_int = va_arg(arg, intmax_t)))
			return (-1);
	}
	else if ((*word)->conv == 'p')
	{
		if (!((*word)->a_t.a_ptr = va_arg(arg, void *)))
			return (-1);
	}
	else if ((*word)->conv == 's')
	{
		if (!((*word)->a_t.a_string = va_arg(arg, char *)))
			return (-1);
	}
	else if ((*word)->conv == 'f')
		return (get_f_type(&(*word), arg));
	else if (((*word)->conv == 'd' || (*word)->conv == 'i' || (*word)->conv == 'o'
				|| (*word)->conv == 'u' || (*word)->conv == 'x' || (*word)->conv == 'X'))
		return (get_dioux_type(&(*word), arg));
	return (0);
}

int     get_f_type(t_ptf **word, va_list arg)
{
	if (!((*word)->flags) || ((*word)->flags[0] != 'l'
				&& (*word)->flags[0] != 'L'))
	{
		if (!((*word)->a_t.a_ldouble = (double)va_arg(arg, double)))
			return (-1);
	}
	else if ((*word)->flags[0] == 'l')
	{
		if (!((*word)->a_t.a_ldouble = (double)va_arg(arg, double)))
			return (-1);
	}
	else if ((*word)->flags[0] == 'L')
	{
		if (!((*word)->a_t.a_ldouble = (long double)va_arg(arg, long double)))
			return (-1);
	}

	return (0);
}

int     get_dioux_type(t_ptf **word, va_list arg)
{
	if (((*word)->conv == 'd' || (*word)->conv == 'i'))
	{
		if (!(*word)->flags)
		{
			if (!((*word)->a_t.a_int = (int)va_arg(arg, intmax_t)))
				return (-1);
		}
		else
			return ((get_di_type(&(*word), arg)));
	}
	else if ((*word)->conv == 'o' || (*word)->conv == 'u' ||  (*word)->conv == 'x'
			|| (*word)->conv == 'X')
	{
		(*word)->unsignd = 1;
		if (!(*word)->flags)
		{
			if (!((*word)->a_t.a_uint = (unsigned int)va_arg(arg, uintmax_t)))
				return (-1);
		}
		else
			return ((get_oux_type(&(*word), arg)));
	}
	return (0);
}


int     get_di_type(t_ptf **word, va_list arg)
{
	if ((*word)->flags[0] == 'h' && (*word)->flags[1] != 'h')
	{
		if (!((*word)->a_t.a_ushort = (short)va_arg(arg, intmax_t)))
			return (-1);
	}
	else if ((*word)->flags[0] == 'h' && (*word)->flags[1] == 'h')
	{
		if (!((*word)->a_t.a_uint = (char)va_arg(arg, intmax_t)))
			return (-1);
	}
	else if ((*word)->flags[0] == 'l' && (*word)->flags[1] != 'l')
	{
		if (!((*word)->a_t.a_ulong = (unsigned long)va_arg(arg, unsigned long)))
			return (-1);
	}
	else if ((*word)->flags[0] == 'l' && (*word)->flags[1] == 'l')
		if (!((*word)->a_t.a_ullong = (unsigned long long)va_arg(arg, unsigned long long)))
			return (-1);
	return (0);
}

int     get_oux_type(t_ptf **word, va_list arg)
{
	if ((*word)->flags[0] == 'h' && (*word)->flags[1] != 'h')
	{
		if (!((*word)->a_t.a_int = (unsigned short)va_arg(arg, uintmax_t)))
			return (-1);
	}
	else if ((*word)->flags[0] == 'h' && (*word)->flags[1] == 'h')
	{
		if (!((*word)->a_t.a_int = (unsigned char)va_arg(arg, uintmax_t)))
			return (-1);
	}
	else if ((*word)->flags[0] == 'l' && (*word)->flags[1] != 'l')
	{
		if (!((*word)->a_t.a_ulong = (unsigned long)va_arg(arg, unsigned long)))
			return (-1);
	}
	else if ((*word)->flags[1] == 'l' && (*word)->flags[1] == 'l')
		if (!((*word)->a_t.a_ullong = (unsigned long long)va_arg(arg, unsigned long long)))
			return (-1);
	return (0);
}

