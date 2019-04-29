/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:37:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/29 14:54:29 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_flags_binary(const char *format)
{
	int i;

	flags = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
				if (format[i] == '+')
				{
					flags = 1 << 6;
					if (format[i] == 'd' || format[i] == 'i' || format[i] == 'f')
						ft_putchar('+');
				}
				if (format[i] =='#')
					flags = 1 << 5;
				if (format[i] == '0')
					flags = 1 << 4;
				if (format[i] == ' ')
					flags = 1 << 3;
				if (format[i] >= 0 && format[i] <= 9)
					ft_atoi(format);
				if (format[i] =='h')
					flags = 1 << 2;
				if (format[i] == '.')
				if (format[i] == 'p')
					flags = 1 << 1;
				if (format[i] == '+')
					flags = 1 << 0;
			i++;
		}
	}
	return (flags);
}
