/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:50:51 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/20 20:25:10 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (dst[len] != '\0')
		len++;
	while ((src[i] != '\0') && (i < n))
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	dst[len++] = '\0';
	return (dst);
}
