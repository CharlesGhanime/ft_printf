/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:38:26 by aboitier          #+#    #+#             */
/*   Updated: 2019/07/24 16:20:49 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count(long long n, unsigned long long *dec)
{
	unsigned long long	count;
	long long			abs;

	count = 1;
	if (n < 0)
	{
		count++;
		abs = -n;
	}
	else
		abs = n;
	while (abs > 9)
	{
		abs = abs / 10;
		count++;
		*dec *= 10;
	}
	return (count);
}

char			*ft_lltoa(long long n)
{
	char				*ascii;
	size_t				i;
	unsigned long long	dec;
	long long			abs;

	dec = 1;
	i = -1;
	if (!(ascii = (char *)malloc(sizeof(char) * ft_count(n, &dec) + 1)))
		return (0);
	if (n < 0)
	{
		ascii[++i] = '-';
		abs = -n;
	}
	else
		abs = n;
	while (dec)
	{
		ascii[++i] = abs / dec % 10 + 48;
		dec /= 10;
	}
	ascii[++i] = '\0';
	return (ascii);
}
