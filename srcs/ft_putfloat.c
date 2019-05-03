/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:11:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/02 17:43:49 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putfloat(double myfloat)
{
	signed long int intpart;
	signed long int decipart;

	if (myfloat < 1)
	{
		ft_putchar('-');
		myfloat *= -1;
	}
	intpart = (signed long int)myfloat;
	ft_putstr(ft_itoa_base(intpart, 10));
	ft_putchar('.');
	myfloat -= intpart;
	myfloat *= 100000000;
	decipart = (signed long int)(myfloat);
//	printf("%ld", decipart);
	ft_putstr(ft_itoa_base(decipart, 10));
}

int main()
{
	ft_putfloat(3.1415171822);
}
