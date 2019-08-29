/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 01:20:46 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/29 02:04:10 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

typedef int							t_boolean;
# define TRUE 1
# define FALSE 0

# define HASH 	00000001
# define ZERO 	00000010
# define MINUS 	00000100
# define PLUS	00001000
# define SPACE	00010000

typedef struct						s_args
{
	intmax_t						a_intmax;
	uintmax_t						a_uintmax;
	char							*a_string;
	void							*a_ptr;
	long double						a_ldouble;
}									t_args;

typedef struct						s_ftprintf
{
	char							conv;
	int								rank;
	int								pos;
	int								options;
	long							width;
	long							precision;
	char							*flags;
	char							*symptoms;
	char							*type;
	int								key;
	char							*keyc;
	int								total_pct_count;
	unsigned long					size;
	int								unsignd;
	char							signe;
	struct s_ftprintf				*next;
	t_args							a_t;
}									t_ptf;

typedef int							(*t_pfunc)(t_ptf *);

typedef enum						e_format_token
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
	PERCENT,
	INVALID,
	NB_FORMAT,
	NO_FORMAT
}									t_format_token;

typedef struct						s_format
{
	char							token;
	t_pfunc							func;
	t_format_token					next_format;
}									t_format;

typedef struct						s_stock
{
	int								flags;
	int								fw;
	int								pr;
	struct s_stock					*next;
}									t_stock;

/*
** SYSTEM
*/

t_boolean							is_token(char token, char c);
t_boolean							is_format(size_t bool_format);

/*
** GET FUNCTIONS
*/

char								ft_get_char(void);
char								ft_get_string(void);
char								ft_get_address(void);
char								ft_get_decimal(void);
char								ft_get_integer(void);
char								ft_get_octal(void);
char								ft_get_unsigned(void);
char								ft_get_hexa(void);
char								ft_get_hexa_maj(void);
char								ft_get_float(void);
char								ft_get_percent(void);
char								ft_get_invalid(void);

/*
** PRINTF
*/

int									ft_printf(const char *format, ...);
void								ft_lst_token_init(t_format lst_format
									[NB_FORMAT]);
void								ft_lst_format_init(t_format lst_format
									[NB_FORMAT]);
void								ft_lst_pfunc_init(t_format lst_format
									[NB_FORMAT]);

void								ft_lst_format_token_init(t_format
									lst_format[NB_FORMAT]);
void								ft_format_cmp(char c, t_ptf *percents);
long								total_size(t_ptf *head, int char_size);
t_pfunc								ft_get_print_char(void);
t_pfunc								ft_get_print_string(void);
t_pfunc								ft_get_print_address(void);
t_pfunc								ft_get_print_decimal(void);
t_pfunc								ft_get_print_integer(void);
t_pfunc								ft_get_print_octal(void);
t_pfunc								ft_get_print_unsigned(void);
t_pfunc								ft_get_print_hexa(void);
t_pfunc								ft_get_print_hexa_maj(void);
t_pfunc								ft_get_print_float(void);
t_pfunc								ft_get_print_percent(void);
t_pfunc								ft_get_print_invalid(void);

int									ft_print_char(t_ptf *percents);
int									ft_print_string(t_ptf *percents);
int									ft_print_address(t_ptf *percents);
int									ft_print_decimal(t_ptf *percents);
int									ft_print_integer(t_ptf *percents);
int									ft_print_octal(t_ptf *percents);
int									ft_print_unsigned(t_ptf *percents);
int									ft_print_hexa(t_ptf *percents);
int									ft_print_hexa_maj(t_ptf *percents);
int									ft_print_float(t_ptf *percents);
int									ft_print_percent(t_ptf *percents);
int									ft_print_invalid(t_ptf *percents);
int									ft_print_generic(t_ptf *percents,
									char *base);
int									ft_print_float_generic(t_ptf *percents);
int									ft_print_empty(t_ptf *percents);
int									ft_print_address(t_ptf *percents);

char								*get_octal_var(t_ptf *percents);
char								*get_unsigned_var(t_ptf *percents);
char								*get_hexa_var(t_ptf *percents);
char								*get_hexa_maj_var(t_ptf *percents);
char								*get_generic_var(t_ptf *percents,
									char *base);
char								*get_float_generic_var(t_ptf *percents);
char								*convert_h_and_signs(t_ptf *percents,
									char *base);
char								*convert_hh_and_signs(t_ptf *percents,
									char *base);
char								*convert_l_and_signs(t_ptf *percents,
									char *base);
char								*convert_ll_and_signs(t_ptf *percents,
									char *base);

/*
** GESTION DES FLAGS
*/

void								ft_minus_flag(t_ptf *percents, size_t nb);
void								ft_plus_flag(va_list arg, t_ptf *percents);
char								*ft_hashtag_flag(t_ptf *percents,
									char *str);
char								*ft_hashtag_p(t_ptf *percents,
									char *str);
char								*ft_hashtag_o(t_ptf *percents, char *str);
char								*ft_hashtag_x(t_ptf *percents, char *str);
char								*ft_hashtag_cap_x(t_ptf *percents,
									char *str);
void								ft_zero_flag(t_ptf *word, size_t nb);
char								*float_prec_flag(char *str, int prec);
char								*float_prec_flag2(char *str, int i);
char								*clean_round(char *str, int i);
char								*fill_prec(char *str, int diff);
char								*ft_addonechar(char **str, char c);
char								*ft_width_precision(char *src,
									t_ptf *percents);
char								*str_width(char *str, long width,
									t_ptf *percents, char c);
char								*str_precision(char *str, long precision);
char								*int_precision(char *str, long precision,
									int len);
char								*int_width(char *str, long width, long len,
									t_ptf *percents);
char								*manage_opts(char *str, t_ptf *percents);

/*
** PARSING
*/

int									ft_count_pct(char *format, t_ptf **head);
int									ft_auscultate(char *patient);
int									doctor(char *format, int rank, int position,
									t_ptf **percents);
int									add_pct_pos(t_ptf **percents, int pos);

t_ptf								*init_head(t_ptf *head);
int									init_conv(t_ptf **percents, int rank,
									char *symptoms, char conv);
int									init_args(t_ptf *word);
int									blood_test(t_ptf **percents, va_list arg);
int									get_type(t_ptf **word, va_list arg);
int									get_f_type(t_ptf **word, va_list arg);
int									get_dioux_type(t_ptf **word, va_list arg);
int									get_di_type(t_ptf **word, va_list arg);
int									get_oux_type(t_ptf **word, va_list arg);
int									get_options(t_ptf **word, int i);
int									get_width(t_ptf **word, int i);
int									get_precision(t_ptf **word, int i);
int									get_flags(t_ptf **word, int i);

t_stock								*flags_struct_creation(void);
t_stock								*flags_struct_completion(t_stock *head,
									int flags, int fw, int pr);

/*
** PRINT DEBUG
*/

void								word_info(t_ptf *word);
void								global_info(t_ptf *percents);

/*
** MAIN
*/

int									main(void);

/*
** COLORS
*/

# define _RED       "\x1b[31m"
# define _BRED      "\x1b[1;31m"
# define _GREEN     "\x1b[32m"
# define _BGREEN    "\x1b[1;32m"
# define _YELLOW    "\x1b[33m"
# define _BLUE      "\x1b[34m"
# define _BBLUE     "\x1b[1;34m"
# define _MAGENTA   "\x1b[35m"
# define _BMAGENTA  "\x1b[1;35m"
# define _CYAN      "\x1b[36m"
# define _END       "\x1b[0m"

#endif
