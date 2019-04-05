/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:58:27 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/05 14:47:48 by cghanime         ###   ########.fr       */
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

typedef enum 
{
	false,
	true
} bool;

typedef int (*p_func)(va_list);

typedef enum 
{
	c = 0, s, p, d, i, o, u, x, X, nb_formats, no_format
} FORMAT_TOKEN;

typedef struct		s_format
{
	char			token;
	p_func			func;
	FORMAT_TOKEN	next_format;
}					t_format;

/**************************** SYSTEM ******************************************/

size_t		ft_strlen(const char *str);
bool		is_tokn(char token, char c);
bool		is_format(size_t	bool_format);

/**************************** GET FUNCTIONS ***********************************/

char		get_char();
char		get_string();
char		get_address();
char		get_dec();
char		get_integer();
char		get_octal();
char		get_unsigned();
char		get_hexa();
char		get_HEXA();

/**************************** PRINT FUNCTIONS *********************************/

void		ft_putchar(char c);
void		ft_putstr(char const *str);
void		ft_putnbr(int nb);
char		*ft_itoa_base(unsigned int nb, unsigned int base);

/**************************** PRINTF ******************************************/

int			ft_printf(const char *format, ...);

void		ft_lst_format_token_init(t_format lst_format[nb_formats]);
void		ft_format_cmp(va_list arg, char c);

p_func		ft_get_print_char();
p_func		ft_get_print_string();
p_func		ft_get_print_address();
p_func		ft_get_print_dec();
p_func		ft_get_print_integer();
p_func		ft_get_print_octal();
p_func		ft_get_print_unsigned();
p_func		ft_get_print_hexa();
p_func		ft_get_print_HEXA();

int			ft_print_char(va_list arg);
int			ft_print_string(va_list arg);
int			ft_print_address(va_list arg);
int			ft_print_dec(va_list arg);
int			ft_print_integer(va_list arg);
int			ft_print_octal(va_list arg);
int			ft_print_unsigned(va_list arg);
int			ft_print_hexa(va_list arg);
int			ft_print_HEXA(va_list arg);


/**************************** MAIN ********************************************/

int		main(void);

# endif
