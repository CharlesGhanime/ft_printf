/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_needed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:17:23 by cghanime          #+#    #+#             */
/*   Updated: 2019/03/27 16:07:33 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cprintf.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i;
	int length;

	i = 0;
	length = 0;
	while (str[i])
	{
		length++;
		i++;
	}
	printf("%d\n", length);
	return (length);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	write(1, &str[i], ft_strlen(str));
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb > -10)
			ft_putchar(-nb);
		else 
		{
			ft_putnbr(-(nb / 10));
			ft_putnbr(-(nb % 10));
		}
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

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

int		ft_counter(char *str)
{
	int counter;

	counter = 0;
	while(*(str++))
		counter++;
	return (counter);
}

char	*ft_itoa_base(int nb, int base)
{
	int neg;
	char *tab;
	size_t len;

	neg = (nb > 0) ? 1 : 0;
	nb = (neg == 1) ? nb * -1 : nb;
	len = ft_counter(tab);
	if (!(tab = (char *)malloc(sizeof(char) * len + neg + 1)))
		return (NULL);
	tab[len + neg] = '\0';
	while (len > 0)
	{
		tab[len-- + neg] = nb % base + '0';
		nb = nb / base;
	}
	tab[0] = neg == 1 ? '-' : tab[0];
	return (tab);
}

int		main(void)
{
	ft_putnbr_base(42, 16);
	ft_itoa_base(42, 16);
	return (0);
}
