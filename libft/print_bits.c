/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:11:24 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/29 15:21:48 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void ft_print_bits(unsigned int octet)
{
	int i;

	i = 1;
	while (octet)
	{
		(octet & i ? write(1, "1", 1) : write(1, "0", 1));
		octet >>= i;
	}
}

int main()
{
	float octet = 3.14;
	ft_print_bits(octet);
	return(0);
}
