/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 01:20:46 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/09 00:45:00 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

#define HASH 	00000001
#define ZERO 	00000010
#define MINUS 	00000100
#define PLUS	00001000
#define SPACE	00010000


typedef struct				u_args
{
	int						a_int;
	long					a_long;
	long long				a_llong;
	unsigned char			a_unchar;
	unsigned int			a_uint;
	unsigned short			a_unshort;
	unsigned long			a_ulong;
	unsigned long long		a_ullong;
	//char				a_char;
	char 					*a_string;
	void					*a_ptr;
	long double				a_ldouble;
}							t_args;

typedef struct				s_ftprintf
{
	char					conv;
	int						rank;
	int						pos;
	int						options;
	long					width;
	long					precision;
	char					*flags;
	char					*symptoms;
	char					*type;
	int						key;
	char					*keyc;
	int						total_pct_count;
	unsigned long			size;
	int						unsignd;
	char					signe;
	struct s_ftprintf		*next;
	t_args				a_t;
}					t_ptf;

typedef int (*p_func)(t_ptf *);

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

/**************************** SYSTEM ******************************************/

boolean						is_token(char token, char c);
boolean						is_format(size_t bool_format);

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

/********************************* PRINTF *************************************/

int							ft_printf(const char *format, ...);

void						ft_lst_format_token_init(t_format lst_format[NB_FORMAT]);
void						ft_format_cmp(char c, t_ptf *percents);
long						total_size(t_ptf *head, int char_size);
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

int							ft_print_char(t_ptf *percents);
int							ft_print_string(t_ptf *percents);
int							ft_print_address(t_ptf *percents);
int							ft_print_decimal(t_ptf *percents);
int							ft_print_integer(t_ptf *percents);
int							ft_print_octal(t_ptf *percents);
int							ft_print_unsigned(t_ptf *percents);
int							ft_print_hexa(t_ptf *percents);
int							ft_print_hexa_maj(t_ptf *percents);
int							ft_print_float(t_ptf *percents);

/**************************** GESTION DES FLAGS *******************************/

void	    				ft_minus_flag(t_ptf *percents, size_t nb);
void						ft_plus_flag(va_list arg, t_ptf *percents);
void						ft_hashtag_flag(t_ptf *percents, char *str);
void						ft_zero_flag(t_ptf *word, size_t nb);
char						*ft_float_precision_flag(char *str);
char                        *ft_width_precision(char *src, t_ptf *percents);
char						*str_width(char *str, long width, t_ptf *percents, char c);
char						*str_precision(char *str, long precision);
char						*int_precision(char *str, long precision, int len, t_ptf *percents);

/***************************** PARSING ****************************************/

int							ft_count_pct(char *format, t_ptf **head);
int							ft_auscultate(char *patient);
int							doctor(char *format, int rank, int position, t_ptf
							**percents);
int							add_pct_pos(t_ptf **percents, int pos);

t_ptf						*init_head(t_ptf *head);
int							init_conv(t_ptf **percents, int rank, char *symptoms, char conv);
int							init_args(t_ptf *word);
int							blood_test(t_ptf **percents, va_list arg);
int							get_type(t_ptf **word, va_list arg);
int							get_f_type(t_ptf **word, va_list arg);
int							get_dioux_type(t_ptf **word, va_list arg);
int							get_di_type(t_ptf **word, va_list arg);
int							get_oux_type(t_ptf **word, va_list arg);
int							get_options(t_ptf **word, int i);
int							get_width(t_ptf **word, int i);
int							get_precision(t_ptf **word, int i);
int							get_flags(t_ptf **word, int i);

t_stock						*flags_struct_creation();
t_stock						*flags_struct_completion(t_stock *head, int flags,
							int fw, int pr);


/***************************** PRINT DEBUG ************************************/

void						word_info(t_ptf *word);
void						global_info(t_ptf *percents);

/********************************** MAIN **************************************/

int							main(void);

/********************************************************************************
 *                                                                               *
 *                                   COLORS                                      *
 *                                                                               *
 ********************************************************************************/

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
