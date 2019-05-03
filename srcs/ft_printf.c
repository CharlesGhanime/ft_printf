/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:00:06 by cghanime          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/30 16:19:08 by cghanime         ###   ########.fr       */
=======
/*   Updated: 2019/04/30 14:44:40 by aboitier         ###   ########.fr       */
>>>>>>> 41a855f9a08177687b6a978d7cbdad4b20b58a34
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

boolean			is_token(char token, char c)
{
	if (c == token)
		return (TRUE);
	return (FALSE);
}

boolean			is_format(size_t bool_format)
{
	if (bool_format != TRUE)
		return (TRUE);
	return (FALSE);
}

void			ft_lst_format_token_init(t_format lst_format[NB_FORMAT])
{
	lst_format[CHAR].token = ft_get_char();
	lst_format[STRING].token = ft_get_string();
	lst_format[ADDRESS].token = ft_get_address();
	lst_format[DECIMAL].token = ft_get_decimal();
	lst_format[INTEGER].token = ft_get_integer();
	lst_format[OCTAL].token = ft_get_octal();
	lst_format[UNSIGNED].token = ft_get_unsigned();
	lst_format[HEXA].token = ft_get_hexa();
	lst_format[HEXA_MAJ].token = ft_get_hexa_maj();

	lst_format[CHAR].next_format = STRING;
	lst_format[STRING].next_format = ADDRESS;
	lst_format[ADDRESS].next_format = DECIMAL;
	lst_format[DECIMAL].next_format = INTEGER;
	lst_format[INTEGER].next_format = OCTAL;
	lst_format[OCTAL].next_format = UNSIGNED;
	lst_format[UNSIGNED].next_format = HEXA;
	lst_format[HEXA].next_format = HEXA_MAJ;
	lst_format[HEXA_MAJ].next_format = NO_FORMAT;

	lst_format[CHAR].func = ft_get_print_char();
	lst_format[STRING].func = ft_get_print_string();
	lst_format[ADDRESS].func = ft_get_print_address();
	lst_format[DECIMAL].func = ft_get_print_decimal();
	lst_format[INTEGER].func = ft_get_print_integer();
	lst_format[OCTAL].func = ft_get_print_octal();
	lst_format[UNSIGNED].func = ft_get_print_unsigned();
	lst_format[HEXA].func = ft_get_print_hexa();
	lst_format[HEXA_MAJ].func = ft_get_print_hexa_maj();
}

void			ft_format_cmp(va_list arg, char c)
{
	size_t			check_format = FALSE;
	t_format		lst_format[NB_FORMAT];
	FORMAT_TOKEN	current_format = CHAR;

	ft_lst_format_token_init(lst_format);
	while (current_format != NO_FORMAT)
	{
		//rajouter les checks des flags ici
		if (lst_format[current_format].token == c)
		{
			lst_format[current_format].func(arg);
			//checker la valeur des bits de l'int flags ici et appeler les fonctions de flags correspondantes.
			check_format = TRUE;
		}
		current_format = lst_format[current_format].next_format;
	}
	if (is_format(check_format) == TRUE)
	{
		ft_putchar('%');
		ft_putchar(c);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	t_ptf		*percents;
	int i;

	percents = init_head(percents);
	ft_count_pct(format, &percents);
	va_start(arg, format);
	i = 0;
	
	while (format[i])
	{
		if (is_token('%', format[i]) == TRUE)
		{
			ft_format_cmp(arg, format[++i]);
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(arg);
		return (ft_strlen(format));
}
