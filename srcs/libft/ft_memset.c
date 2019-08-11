/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:04:35 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/24 13:30:37 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;

	if (len == 0)
		return (str);
	s = (unsigned char *)str;
	while (len-- != 0)
		*s++ = (unsigned char)c;
	return (str);
}
