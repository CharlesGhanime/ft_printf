/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 05:35:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/30 00:22:53 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	s = s + start;
	while (s[i] && i != len)
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (new == 0)
		return (0);
	i = 0;
	while (i != len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
