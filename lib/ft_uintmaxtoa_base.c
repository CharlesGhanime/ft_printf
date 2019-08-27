/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:58:57 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/28 00:38:26 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uintmaxtoa_base(uintmax_t value, char *base)
{
	intmax_t			count;
	uintmax_t			tmp;
	char				*res;
	uint64_t			base_length;

	base_length = ft_strlen(base);
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}
