/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:02:24 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/25 07:19:09 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*cdst;
	char		*csrc;
	size_t		i;

	cdst = (char *)dst;
	csrc = (char *)src;
	i = 0;
	while (i < len)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (cdst);
}
