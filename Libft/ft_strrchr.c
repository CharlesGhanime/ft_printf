/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:28:32 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/23 13:51:29 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *locate;

	locate = (0);
	while (*s)
	{
		if (*s == c)
			locate = (char *)s;
		++s;
	}
	if (locate)
		return (locate);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
