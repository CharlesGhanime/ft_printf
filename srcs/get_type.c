/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 07:11:25 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/07 11:34:01 by cghanime         ###   ########.fr       */
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

int		blood_test(t_ptf **percents)
{
	t_ptf	*word;	
	int		i;
	int		j;

//	va_start(ap, format);
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
		if ((get_type(&word)) == -1)
			return (-1);
//		if ((create_key(&word)) == -1)
//			return (-1);
		word = word->next;
	}
	return (0);
}

int		get_type(t_ptf **word)
{
	if ((*word)->conv == 'c')
	{
		if (!((*word)->type = (char *)ft_strdup("char")))
			return (-1);
	}
	else if ((*word)->conv == 'p')
	{
		if (!((*word)->type = (char *)ft_strdup("void *")))
			return (-1);
	}
	else if ((*word)->conv == 's')
	{
		if (!((*word)->type = (char *)ft_strdup("char *")))
			return (-1);
	}
	else if ((*word)->conv == 'f')
		return (get_f_type(&(*word)));
	else if (((*word)->conv == 'd' || (*word)->conv == 'i' || (*word)->conv == 'o'
		|| (*word)->conv == 'u' || (*word)->conv == 'x' || (*word)->conv == 'X'))
		return (get_dioux_type(&(*word)));
	return (0);
}

int		get_f_type(t_ptf **word)
{
	int	i;

	i = 0;
	if (!((*word)->flags) || ((*word)->flags[i] != 'l' 
		&& (*word)->flags[i] != 'L'))
	{
		if (!((*word)->type = (char *)ft_strdup("float")))
			return (-1);
	}
	else if ((*word)->flags[i] == 'l')
	{
		if (!((*word)->type = (char *)ft_strdup("double")))
			return (-1);
	}
	else if ((*word)->flags[i] == 'L')
	{
		if (!((*word)->type = (char *)ft_strdup("long double")))
			return (-1);
	}

	return (0);
}

int		get_dioux_type(t_ptf **word)
{
	if (((*word)->conv == 'd' || (*word)->conv == 'i'))
	{
		if (!(*word)->flags)
		{	
			if (!((*word)->type = (char *)ft_strdup("int")))
				return (-1);
		}
		else
			return ((get_di_type(&(*word))));
	}		
	else if ((*word)->conv == 'o' || (*word)->conv == 'u' ||  (*word)->conv == 'x' 
			|| (*word)->conv == 'X')
	{	
		if (!(*word)->flags)	
		{	
			if (!((*word)->type = (char *)ft_strdup("unsigned int")))
				return (-1);	
		}
		else
			return ((get_oux_type(&(*word))));
	}
	return (0);
}

int		get_di_type(t_ptf **word)
{
	size_t i;

	i = 0;
	while ((*word)->flags[i] && (*word)->type == NULL)
	{
		if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] != 'h')
		{
			if (!((*word)->type = (char *)ft_strdup("short")))
				return (-1);
		}
		else if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] == 'h')
		{
			if (!((*word)->type = (char *)ft_strdup("char")))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] != 'l') 
		{
			if (!((*word)->type = (char *)ft_strdup("long")))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] == 'l')
			if (!((*word)->type = (char *)ft_strdup("long long")))
				return (-1);
	}					
	return (0);	
}

int		get_oux_type(t_ptf **word)
{
	size_t i;

	i = 0;
	while ((*word)->flags[i] && (*word)->type == NULL)
	{
		if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] != 'h')
		{
			if (!((*word)->type = (char *)ft_strdup("unsigned short")))
				return (-1);	
		}
		else if ((*word)->flags[i] == 'h' && (*word)->flags[i + 1] == 'h')
		{
			if (!((*word)->type = (char *)ft_strdup("unsigned char")))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] != 'l')
		{
			if (!((*word)->type = (char *)ft_strdup("unsigned long")))
				return (-1);
		}
		else if ((*word)->flags[i] == 'l' && (*word)->flags[i + 1] == 'l')
			if (!((*word)->type = (char *)ft_strdup("unsigned long long")))
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
			width = (width * 10) + ft_atoi(&(*word)->symptoms[i]);
	if (width > 10)
		width = width / 10;
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
		precision = (precision * 10) + ft_atoi(&(*word)->symptoms[i]);
	if (precision > 10)
		precision = precision / 10;
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
