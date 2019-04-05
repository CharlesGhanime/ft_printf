/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:53:05 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/05 14:13:40 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int		ft_printf(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	int index;
	int d;
	char c;
	char *s;

	index = 0;

	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == 'd' || format[index + 1] == 'i')
			{
				printf("format : %s\n", format);
				d = va_arg(arg, int);
				ft_putnbr(d);
			}
			else if (format[index + 1] == 'c')
			{
//				printf("format : %s\n", format);
				c = va_arg(arg, int);
					ft_putchar(c);
			}
			else if (format[index + 1] == 's')
			{
//				printf("format : %s\n", format);
				s = va_arg(arg, char *);
					ft_putstr(s);
			}
		}
		else //(format[index] != '\0' && format[index] != '%')
			ft_putchar(format[index]);
		index++;
	}
	return (index);
}
