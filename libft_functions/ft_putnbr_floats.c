/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_floats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 09:45:12 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/01 17:44:57 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libc.h>
#include "../../includes/ft_printf.h"

void	*ft_print_floats(va_list *ap, t_flag *flags)
{
	double myfloat;
	signed long int decipart;
	signed long int intpart;

	myfloat = va_arg(*ap, double);
	if (myfloat < 0)
	{
		ft_putchar('-');
		myfloat *= -1;
	}
	intpart = (signed long int)myfloat;
	ft_putnbr(intpart);
	ft_putchar('.');
	myfloat -= intpart;
	myfloat *= 1000000;  //upto 6 decimal points
	decipart = (signed long int)(myfloat + 0.5); //+0.5 to round of the value
	ft_putnbr(decipart);
}
