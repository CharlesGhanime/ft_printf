/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:08:49 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/16 11:25:26 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flag_sign(va_list arg)
{
	if (va_arg(arg, int) >= 0 || va_arg(arg, float) >= 0)
		ft_putchar('+');
	else
		ft_putchar('-');
}
