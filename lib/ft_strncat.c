/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:50:51 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/03 12:11:47 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dst, char *src, size_t n)
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
