/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:38:26 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/28 06:07:56 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count(long long n, long long *dec)
{
	long long	count;
	long long	abs;

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

char			*ft_ltoa(long long  n)
{
	char				*ascii;
	long long			i;
	long long			dec;
	long long			abs;

	dec = 1;
	i = -1;
	if (n == -9223372036854775808)
		return(ft_strdup("-9223372036854775808"));
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

/*
#include <stdio.h>

int main ()
{
	printf("%s\n", ft_ltoa(-9223372036854775808));
	return (0);
}*/
