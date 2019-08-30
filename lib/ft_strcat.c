/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:29:44 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/30 05:27:20 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char *src)
{
	int count;
	int i;

	count = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[count] = src[i];
		i++;
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
