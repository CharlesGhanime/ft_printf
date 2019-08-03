/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addonecharpos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:18:00 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/04 01:34:02 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static char		*strposcpy(char *dst, char *src, int pos, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[j])
	{
		if (i == pos)
		{
			dst[i] = c;
			i++;
		}
		dst[i] = src[j];
		i++;
		j++;
	}	
	return (dst);
}

char			*ft_addonecharpos(char **str, char c, int pos)
{
	char	*new;
	size_t	size;

	if (pos < 0)
		pos = ft_strlen(*str);
	size = 0;
	if (*str)
	{
		size = ft_strlen(*str);
		if (!(new = (char *)malloc(sizeof(char) * size + 2)))
			return (0);
		new = strposcpy(new, *str, pos, c);
		new[size + 1] = '\0';
		free(*str);
		return (new);
	}
	else
	{
		new = (char*)ft_memalloc(2);
		new[size] = c;
		new[size + 1] = '\0';
		return (new);
	}
	return (NULL);
}
