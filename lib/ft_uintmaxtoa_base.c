/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:58:57 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/28 21:24:48 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_uintmaxtoa_base(uint64_t value, char *base)
{
	int64_t				count;
	uint64_t			tmp;
	char				*res;
	uint64_t			base_length;

	base_length = ft_strlen(base);
	count = 1;
	tmp = value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = value;
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
