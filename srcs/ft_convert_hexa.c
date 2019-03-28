/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 07:19:54 by cghanime          #+#    #+#             */
/*   Updated: 2019/03/28 07:38:59 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_convert_x(unsigned int nb)
{
	char *hexa;
	int q;
	int r;

	hexa = "0123456789abcdef";
	if (nb < 16)
		write(1, hexa[nb], 1);
	else
	{
		q = nb / 16;
		write(1, hexa[nb], 1);
		r = nb % 16;
		write(1, hexa[nb], 1);
	}
}
