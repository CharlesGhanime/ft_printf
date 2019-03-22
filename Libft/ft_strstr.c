/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:31:43 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/24 20:52:35 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t pos;
	size_t i;

	pos = 0;
	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[pos])
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] && str[pos + i] == to_find[i])
				++i;
			if (to_find[i] == '\0')
				return ((char *)&str[pos]);
		}
		++pos;
	}
	return (0);
}
