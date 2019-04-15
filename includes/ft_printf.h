/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:58:27 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/15 15:13:35 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

//#include "../Libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <libc.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef int (*p_func)(va_list);

typedef enum 
{
	CHAR = 0, STRING, ADDRESS, DECIMAL, INTEGER, OCTAL,
	UNSIGNED, HEXA, HEXA_MAJ, NB_FORMAT, NO_FORMAT
} FORMAT_TOKEN;

typedef struct		s_format
{
	char			token;
	p_func			func;
	FORMAT_TOKEN	next_format;
}					t_format;

/**************************** SYSTEM ******************************************/

size_t		ft_strlen(const char *str);
boolean		is_token(char token, char c);
boolean		is_format(size_t bool_format);

/**************************** GET FUNCTIONS ***********************************/

char		ft_get_char();
char		ft_get_string();
char		ft_get_address();
char		ft_get_decimal();
char		ft_get_integer();
char		ft_get_octal();
char		ft_get_unsigned();
char		ft_get_hexa();
char		ft_get_hexa_maj();

/**************************** PRINT FUNCTIONS *********************************/

void		ft_putchar(char c);
void		ft_putstr(char const *str);
void		ft_putnbr(int nb);
int			ft_atoi(const char *str);
char		*ft_itoa_base(unsigned int nb, unsigned int base);

/**************************** PRINTF ******************************************/

int			ft_printf(const char *format, ...);

void		ft_lst_format_token_init(t_format lst_format[NB_FORMAT]);
void		ft_format_cmp(va_list arg, char c);

p_func		ft_get_print_char();
p_func		ft_get_print_string();
p_func		ft_get_print_address();
p_func		ft_get_print_decimal();
p_func		ft_get_print_integer();
p_func		ft_get_print_octal();
p_func		ft_get_print_unsigned();
p_func		ft_get_print_hexa();
p_func		ft_get_print_hexa_maj();

int			ft_print_char(va_list arg);
int			ft_print_string(va_list arg);
int			ft_print_address(va_list arg);
int			ft_print_decimal(va_list arg);
int			ft_print_integer(va_list arg);
int			ft_print_octal(va_list arg);
int			ft_print_unsigned(va_list arg);
int			ft_print_hexa(va_list arg);
int			ft_print_hexa_maj(va_list arg);


/**************************** MAIN ********************************************/

int		main(void);

# endif
