/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 08:08:42 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/07 11:15:15 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cprintf.h"

bool is_Token(char token, char c)
{
	if (c == token)
		return true;
	return false;
}

bool is_Format(size_t bool_format)
{
	if (bool_format != true)
		return true;
	return false;
}

char get_Integer()
{
	return 'd';
}

char get_Char()
{
	return 'c';
}

char get_String()
{
	return 's';
}

p_func get_IntAff()
{
	return affInt;
}

p_func get_ChAff()
{
	return affCh;
}

p_func get_StrAff()
{
	return affStr;
}

/* Machine à état */

void ini_ListFormat_Token(Format list_format[NB_FORMATS])
{
	list_format[INT].token = get_Integer();
	list_format[CHAR].token = get_Char();
	list_format[STR].token = get_String();

	list_format[INT].next_format = CHAR;
	list_format[CHAR].next_format = STR;
	list_format[STR].next_format = NO_FORMAT;

	list_format[INT].func = get_IntAff();
	list_format[CHAR].func = get_ChAff();
	list_format[STR].func = get_StrAff();
}

void formatCmp(va_list arg, char c)
{
	size_t check_format = false;
	Format list_format[NB_FORMATS];
	ini_ListFormat_Token(list_format);
	FORMATS_TOKEN current_format = INT;

	while (current_format != NO_FORMAT)
	{
		if (list_format[current_format].token == c)
		{
			list_format[current_format].func(arg);
			check_format = true;
		}
		current_format = list_format[current_format].next_format;
	}
	if (is_Format(check_format) == true)
	{
		putCh('%');
		putCh(c);
	}
}

/* Fin machine à état */

void cprintf(char *format, ...)
{
	va_list arg;
	size_t index;
	va_start(arg, format);
	for (index = 0; format[index]; index++)
		if (is_Token('%', format[index]) == true)
			formatCmp(arg, format[++index]);
		else 
			putCh(format[index]); 
	va_end(arg);
	putCh('\n');
}
