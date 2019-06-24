/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 07:19:54 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/01 08:26:56 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_hexa(unsigned int nb)
{
	char *hexa;
	int q;
	int r;

	hexa = "0123456789abcdef";
	if (nb < 16)
		write(1, &hexa[nb], 1);
	else
	{
		q = nb / 16;
		write(1, &hexa[nb], 1);
		r = nb % 16;
		write(1, &hexa[nb], 1);
	}
}

int main(void)
{
	ft_convert_hexa(200);
	return (0);
}
