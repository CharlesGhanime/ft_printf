/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:16:48 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/28 02:54:59 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdint.h>

char	*ft_int128toa_base(uintmax_t value, char *base)
{
	uintmax_t		count;
	uintmax_t		tmp;
	uintmax_t		 base_length;
	char			*res;
	
	if (value == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	base_length = ft_strlen(base);
	count = (value < 0) ? 2 : 1;
	tmp = (value < 0) ? -value : value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (value < 0)
		res[0] = '-';
	res[count] = '\0';
	tmp = (value < 0) ? 2 : 1;
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}

int main()
{
	printf("%s\n", ft_int128toa_base(9223372036854775807, "0123456789abcdef"));
	return (0);
}
