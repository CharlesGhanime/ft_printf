/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:53:05 by cghanime          #+#    #+#             */
/*   Updated: 2019/03/22 17:39:20 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int index;
	int d;
	int c;
	int i;
	int str;

	index = 0;

	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == 'd')
			{
				d = va_arg(args, int);
				ft_putnbr(d);
			}
		}
		index++;
	}
}
