/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finite_state_machine.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:00:06 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/03 13:49:38 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	lst_format_token_ini(t_format lst_format[nb_formats])
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
}
