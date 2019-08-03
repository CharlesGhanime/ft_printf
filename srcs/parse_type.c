/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:11:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/03 20:20:05 by aboitier         ###   ########.fr       */
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

int		get_options(t_ptf **word, int i)
{
	if ((*word)->symptoms)
	{
		while ((*word)->symptoms[++i] && ((*word)->symptoms[i] == '#' || (*word)->symptoms[i] == ' ' || (*word)->symptoms[i] == '+' || (*word)->symptoms[i] == '-' || (*word)->symptoms[i] == '0'))
		{
			if ((*word)->symptoms[i] == '#')
				(*word)->options |= HASH;
			if ((*word)->symptoms[i] == '0')
				(*word)->options |= ZERO;
			if ((*word)->symptoms[i] == '-')
				(*word)->options |= MINUS;
			if ((*word)->symptoms[i] == '+')
				(*word)->options |= PLUS;
			if ((*word)->symptoms[i] == ' ')
				(*word)->options |= SPACE;
		}
	}
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
