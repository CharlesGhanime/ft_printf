/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:45:26 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/01 17:09:06 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(unsigned int nb, unsigned int base)
{
	char *octal;
	char *hexa;

	hexa = "0123456789ABCDEF";
	octal = "0123456710";
	if (base == 2)
	{
		ft_putnbr(nb / 2);
		ft_putnbr(nb % 2);
	}
	if (base == 8)
	{
		ft_putnbr(nb / 8);
		ft_putnbr(nb % 8);
	}
	if (base == 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (base == 16)
	{
		if (nb <=15)
			ft_putchar(hexa[nb]);
		else
		{
			ft_putnbr(nb / 16);
			ft_putnbr(nb % 16);
		}
	}
	else
	{
		ft_putnbr(nb / base);
		ft_putnbr(nb % base);
	}
}
