/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addonechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 03:21:09 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/30 14:13:22 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <string.h>

char			*ft_addonechar(char **str, char c)
{
	char	*new;
	size_t	size;

	size = 0;
	if (*str)
	{
		size = ft_strlen(*str);
		new = (char *)malloc(sizeof(char) * (size + 2));
		if (new == NULL)
			return (0);
		new = ft_strcpy(new, *str);
		new[size] = c;
		new[size + 1] = '\0';
		free(*str);
		*str = NULL;
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
