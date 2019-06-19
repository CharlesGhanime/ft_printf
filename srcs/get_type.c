/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:11:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/06/19 15:29:34 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 	unsigned int X;
 *	+ with X gives undefined behavior
 *	hh with X gives unsigned char
 *	h with X gives unsigned short
 *	ll with X gives unsigned long long
 *	L with X gives unsigned long long
 *	l with X gives unsigned long
 *	
 *	unsigned int x;
 *	l with x gives unsigned long
 *	ll with x gives unsigned long long
 *	hh with x gives unsigned char
 *
 * 	int i;
 *	L with i gives long long
 *	ll with i gives long long
 *	h with i gives short
 *
 * 	unsigned int u;
 *	l with u gives long
 *	ll with u gives unsigned long long
 *	h with u gives unsigned short
 *	hh with u gives unsigned char
 *
 * 	int d; 
 *	l with d gives long	
 *	ll with d gives long long
 *	hh with d gives char
 *	L with d gives long long
 *
 * 	unsigned int o;
 *	l with o gives unsigned long
 *	ll with o gives unsigned long long
 *	h with o gives unsigned short
 *	hh with o gives unsigned char
 *	L with o gives unsigned long long
 *	
 *	
 *	double f;
 *
 */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int		blood_test(t_ptf **percents, va_list arg)
{
	t_ptf	*word;	
	int		i;
	int		j;

	j = -1;
	word = (*percents)->next;
	while (word)
	{
		i = 0;
		// send &word and update: width, type, options,
		if ((i = get_options(&word, i - 1)) == -1)
			return (-1);
		if ((i = get_width(&word, i - 1)) == -1)
			return (-1);
		if ((i = get_precision(&word, i - 1)) == -1)
			return (-1);
		if ((i = get_flags(&word, i - 1)) == -1)
			return (-1);
		if ((get_type(&word, arg)) == -1)
			return (-1);
//		if ((create_key(&word)) == -1)
//			return (-1);
		word = word->next;
	}
	return (0);
}

int		get_type(t_ptf **word, va_list arg)
{
	if ((*word)->conv == 'c')
	{
		if (!((*word)->a_t.a_int = va_arg(arg, int)))
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

int		get_f_type(t_ptf **word, va_list arg)
{
	int	i;

	i = 0;
	if (!((*word)->flags) || ((*word)->flags[i] != 'l' 
		&& (*word)->flags[i] != 'L'))
	{
		if (!((*word)->a_t.a_float = va_arg(arg, double)))
			return (-1);
	}
	else if ((*word)->flags[i] == 'l')
	{
		if (!((*word)->a_t.a_double = va_arg(arg, double)))
			return (-1);
	}
	else if ((*word)->flags[i] == 'L')
	{
		if (!((*word)->a_t.a_ldouble = va_arg(arg, long double)))
			return (-1);
	}

	return (0);
}

int		get_dioux_type(t_ptf **word, va_list arg)
{
	if (((*word)->conv == 'd' || (*word)->conv == 'i'))
	{
		if (!(*word)->flags)
		{	
			if (!((*word)->a_t.a_int = va_arg(arg, int)))
				return (-1);
		}
		else
			return ((get_di_type(&(*word), arg)));
	}		
	else if ((*word)->conv == 'o' || (*word)->conv == 'u' ||  (*word)->conv == 'x' 
			|| (*word)->conv == 'X')
	{	
		if (!(*word)->flags)	
		{	
			if (!((*word)->a_t.a_unint = va_arg(arg, unsigned int)))
				return (-1);	
		}
		else
			return ((get_oux_type(&(*word), arg)));
	}
	return (0);
}

int		get_di_type(t_ptf **word, va_list arg)
{
	size_t i;

	i = 0;
	while ((*word)->flags[i] && (*word)->type == NULL)
	{
		if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] != 'h')
		{
			if (!((*word)->a_t.a_int = va_arg(arg, int)))
				return (-1);
		}
		else if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] == 'h')
		{
			if (!((*word)->a_t.a_int = va_arg(arg, int)))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] != 'l') 
		{
			if (!((*word)->a_t.a_long = va_arg(arg, long)))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] == 'l')
			if (!((*word)->a_t.a_llong = va_arg(arg, long long)))
				return (-1);
	}					
	return (0);	
}

int		get_oux_type(t_ptf **word, va_list arg)
{
	size_t i;

	i = 0;
	while ((*word)->flags[i] && (*word)->type == NULL)
	{
		if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] != 'h')
		{
			if (!((*word)->a_t.a_unshort = va_arg(arg, int)))
				return (-1);	
		}
		else if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] == 'h')
		{
			if (!((*word)->a_t.a_unchar = va_arg(arg, int)))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] != 'l')
		{
			if (!((*word)->a_t.a_unlong = va_arg(arg, unsigned long)))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] == 'l')
			if (!((*word)->a_t.a_unllong = va_arg(arg, unsigned long long)))
				return (-1);
	}
	return (0);
}

int		get_options(t_ptf **word, int i)
{
	if ((*word)->symptoms)
		while (((*word)->symptoms[++i] == '#' || (*word)->symptoms[i] == ' ' || (*word)->symptoms[i] == '+' 
					|| (*word)->symptoms[i] == '-' || (*word)->symptoms[i] == '0') && (*word)->symptoms)
			if (!((*word)->options = ft_addonechar(&(*word)->options, (*word)->symptoms[i])))
				return (-1);
	return (i);
}

int		get_width(t_ptf **word, int i)
{	
	unsigned long		width;

	width = 0;
	if ((*word)->symptoms)
		while (((*word)->symptoms[++i] >= '0' && (*word)->symptoms[i] <= '9') && (*word)->symptoms[i])
			width = (width * 10) + ((*word)->symptoms[i] - '0');
	(*word)->width = width;
	return (i);
}

int		get_precision(t_ptf **word, int i)
{
	unsigned long	precision;

	precision = 0;
	if (!((*word)->symptoms[++i] == '.'))
		return (i);
	while ((*word)->symptoms[++i] && ((*word)->symptoms[i] >= '0' 
		&& (*word)->symptoms[i] <= '9'))
		precision = (precision * 10) + ((*word)->symptoms[i] - '0');
	(*word)->precision = precision;
	return (i);
}

int		get_flags(t_ptf **word, int i)
{
	while ((*word)->symptoms[++i] && ((*word)->symptoms[i] == 'h'
		|| (*word)->symptoms[i] == 'l' || (*word)->symptoms[i] == 'L'))
		if (!((*word)->flags = ft_addonechar(&(*word)->flags,
			(*word)->symptoms[i])))
			return (-1);
	return (1);
}
