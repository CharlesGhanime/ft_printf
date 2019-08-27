/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:11:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/27 23:38:25 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
**		send &word and update: width, type, options,
*/
		i = get_options(&word, i - 1);
		i = get_width(&word, i - 1);
		i = get_precision(&word, i - 1);
		if ((i = get_flags(&word, i - 1)) == -1)
			return (-1);
		get_type(&word, arg);
/*
**		if ((create_key(&word)) == -1)
**			return (-1);
*/
		word = word->next;
	}
	return (0);
}

int		get_options(t_ptf **word, int i)
{
	if ((*word)->symptoms)
	{
		while ((*word)->symptoms[++i] && ((*word)->symptoms[i] == '#'
		|| (*word)->symptoms[i] == ' ' || (*word)->symptoms[i] == '+'
		|| (*word)->symptoms[i] == '-' || (*word)->symptoms[i] == '0'))
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
		while (((*word)->symptoms[++i] >= '0' && (*word)->symptoms[i] <= '9')
		&& (*word)->symptoms[i])
			width = (width * 10) + ((*word)->symptoms[i] - '0');
	(*word)->width = width;
	return (i);
}

int		get_precision(t_ptf **word, int i)
{
	long	precision;

	precision = 0;
	if (!((*word)->symptoms[++i] == '.'))
		return (i);
	if (!((*word)->symptoms[i + 1] >= '0' && ((*word)->symptoms[i + 1] <= '9')))
	{
		(*word)->precision = -1;
		return (i);
	}
	while (((*word)->symptoms[i] && (*word)->symptoms[i + 1] == '0'))
		i++;
	if (!((*word)->symptoms[i + 1]) || ((*word)->symptoms[i + 1] <= '0'
	&& ((*word)->symptoms[i + 1] >= '9')))
	{
		(*word)->precision = -1;
		return (i);
	}
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
