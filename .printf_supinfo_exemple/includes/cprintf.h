/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 08:00:55 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/07 11:15:23 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPRINTF_H 

#define CPRINTF_H
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

typedef enum{ false, true } bool;

/*AFFICHAGE*/

void putCh(const char c);
void putStr(const char *str);
void putInteger(int nb);

/*SYSTEM*/ 

size_t _strlen(const char *str);

/*PRINTF*/

typedef int (*p_func)(va_list);

typedef enum
{
	INT = 0, FLOAT, CHAR, STR, NB_FORMATS, NO_FORMAT
} FORMATS_TOKEN;

typedef struct		s_Format
{
	char			token;
	p_func			func;
	FORMATS_TOKEN	next_format;
}					Format;

typedef int (*p_func)(va_list);

void formatCmp(va_list av, char c);
void cprintf(char *str, ...);
char get_Integer();
char get_Char();
char get_String();
p_func get_IntAff();
p_func get_ChAff();
p_func get_StrAff();
int affStr(va_list av);
int affCh(va_list av);
int affInt(va_list av);

#endif
