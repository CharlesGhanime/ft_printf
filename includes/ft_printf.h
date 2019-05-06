/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:58:27 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/06 10:59:01 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//#include "../Libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef int (*p_func)(va_list);

typedef enum 
{
	CHAR = 0,
	STRING,
	ADDRESS,
	DECIMAL,
	INTEGER,
	OCTAL,
	UNSIGNED,
	HEXA,
	HEXA_MAJ,
	FLOAT,
	NB_FORMAT,
	NO_FORMAT
} FORMAT_TOKEN;

typedef struct				s_format
{
	char					token;
	p_func					func;
	FORMAT_TOKEN			next_format;
}							t_format;

typedef struct				s_stock
{
		int					flags;
		int					fw;
		int					pr;
		struct s_stock		*next;
}							t_stock;


typedef struct				s_ftprintf
{
	char					conv;
	int						rank;
	int						pos;
	char					*options;
	unsigned long			width;
	unsigned long			precision;
	char					*flags;
	char					*symptoms;
	char					*type;
	int						key;
	char					*keyc;
	int						total_pct_count;
	struct s_ftprintf		*next;
}							t_ptf;


/**************************** SYSTEM ******************************************/

size_t						ft_strlen(const char *str);
char						*ft_strcat(char *dst, const char *src);
char						*ft_strcpy(char *dst, char *src);
boolean						is_token(char token, char c);
boolean						is_format(size_t bool_format);
void						ft_bzero(void *str, size_t len);
void						*ft_memset(void *str, int c, size_t len);
void						*ft_memalloc(size_t size);
void						*ft_memcpy(void *dst, const void *src, size_t len);
char						*ft_strsub(char const *s, unsigned int start,
							size_t len);

/**************************** GET FUNCTIONS ***********************************/

char						ft_get_char();
char						ft_get_string();
char						ft_get_address();
char						ft_get_decimal();
char						ft_get_integer();
char						ft_get_octal();
char						ft_get_unsigned();
char						ft_get_hexa();
char						ft_get_hexa_maj();
char						ft_get_float();

/**************************** PRINT FUNCTIONS *********************************/

void						ft_putchar(char c);
void						ft_putstr(char const *str);
void						ft_putnbr(int nb);
int							ft_atoi(const char *str);
char						*ft_itoa_base(unsigned int nb, unsigned int base);
char						*ft_ftoa(double myfloat);

/**************************** PRINTF ******************************************/

int							ft_printf(const char *format, ...);

void						ft_lst_format_token_init(t_format lst_format[NB_FORMAT]);
void						ft_format_cmp(va_list arg, char c);

p_func						ft_get_print_char();
p_func						ft_get_print_string();
p_func						ft_get_print_address();
p_func						ft_get_print_decimal();
p_func						ft_get_print_integer();
p_func						ft_get_print_octal();
p_func						ft_get_print_unsigned();
p_func						ft_get_print_hexa();
p_func						ft_get_print_hexa_maj();
p_func						ft_get_print_float();

int							ft_print_char(va_list arg);
int							ft_print_string(va_list arg);
int							ft_print_address(va_list arg);
int							ft_print_decimal(va_list arg);
int							ft_print_integer(va_list arg);
int							ft_print_octal(va_list arg);
int							ft_print_unsigned(va_list arg);
int							ft_print_hexa(va_list arg);
int							ft_print_hexa_maj(va_list arg);
int							ft_print_float(va_list arg);

/**************************** GESTION DES FLAGS *******************************/

void						ft_minus_flag(va_list arg);

/***************************** PARSING ****************************************/
t_ptf						*ft_count_pct(const char *format, t_ptf **head);
int							ft_auscultate(const char *patient);
int							doctor(char *format, int rank, int position, t_ptf
							**percents);
int							add_pct_pos(t_ptf **percents, int pos);

t_ptf						*init_head(t_ptf *head);
int							init_conv(t_ptf **percents, int rank, char *symptoms, char conv);

t_stock						*flags_struct_creation();
t_stock						*flags_struct_completion
							(t_stock *head, int flags, int fw, int pr);

/**************************** MAIN ********************************************/

int		main(void);

#endif
