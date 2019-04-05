/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finite_state_machine.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:00:06 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/05 14:41:12 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool	is_token(char token, char c)
{
	if (c == token)
		return (true);
	return (false);
}

bool	is_format(size_t bool_format)
{
	if (bool_format != true)
		return (true);
	return (false);
}

void	ft_lst_format_token_init(t_format lst_format[nb_formats])
{
	lst_format[c].token = get_char();
	lst_format[s].token = get_string();
	lst_format[p].token = get_address();
	lst_format[d].token = get_dec();
	lst_format[i].token = get_integer();
	lst_format[o].token = get_octal();
	lst_format[u].token = get_unsigned();
	lst_format[x].token = get_hexa();
	lst_format[X].token = get_HEXA();

	lst_format[c].next_format = s;
	lst_format[s].next_format = p;
	lst_format[p].next_format = d;
	lst_format[d].next_format = i;
	lst_format[i].next_format = o;
	lst_format[o].next_format = u;
	lst_format[u].next_format = x;
	lst_format[x].next_format = X;
	lst_format[X].next_format = no_format;

	lst_format[c].func = ft_get_print_char();
	lst_format[s].func = ft_get_print_string();
	lst_format[p].func = ft_get_print_address();
	lst_format[d].func = ft_get_print_dec();
	lst_format[i].func = ft_get_print_integer();
	lst_format[o].func = ft_get_print_octal();
	lst_format[u].func = ft_get_print_unsigned();
	lst_format[x].func = ft_get_print_hexa();
	lst_format[X].func = ft_get_print_HEXA();
}

void	ft_format_cmp(va_list arg, char c)
{
	size_t	check_format = false;
	t_format	lst_format[nb_formats];
	FORMAT_TOKEN	current_format = c;

	ft_lst_format_token_init(lst_format);
	while (current_format != no_format)
	{
		if (lst_format[current_format].token == c)
		{
			lst_format[current_format].func(arg);
			check_format = true;
		}
		current_format = lst_format[current_format].next_format;
	}
	if (is_format(check_format) == true)
	{
		ft_putchar('%');
		ft_putchar('c');
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	size_t		i;
	va_start(arg, format);
	while (format[i])
		if (is_token('%', format[i]) == true)
			ft_format_cmp(arg, format[++i]);
		else
			ft_putchar(format[i]);
	va_end(arg);
	ft_putchar('\n');
		return (ft_strlen(format));
}
