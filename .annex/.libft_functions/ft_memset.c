/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:04:35 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/04 17:50:42 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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
