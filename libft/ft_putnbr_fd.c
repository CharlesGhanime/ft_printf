/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:05:11 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/22 17:03:41 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_int_limit(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	ft_putchar_fd('1', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('7', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
	ft_putchar_fd('3', fd);
	ft_putchar_fd('6', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_int_limit(fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 0 && n <= 9)
			ft_putchar_fd(n + 48, fd);
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
