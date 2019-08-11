/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:42:39 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/08 03:00:38 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char 	*ft_padding(long padd, char c)
{
	char	*new;
	long	i;

	i = -1;
	if (!(new = (char *)malloc(sizeof(char) * (padd + 1))))
		return (NULL);
	while (++i < padd)
		new[i] = c;
	new[i] = '\0';
	return (new);
}
