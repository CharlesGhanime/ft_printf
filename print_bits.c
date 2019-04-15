/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:11:24 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/15 10:25:15 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void ft_print_bits(unsigned int octet)
{
	int i;
	char lettre;

	i = 1;
	lettre = 'A';
	lettre++;
	while (octet)
	{
		(octet & i ? write(1, &lettre, 1) : write(1, "0", 1));
		octet >>= i;
	}
}

int main()
{
	unsigned int octet = 65535;
	ft_print_bits(octet);
	return(0);
}
