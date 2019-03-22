/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:03:22 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/20 12:51:21 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	if (!s || !f)
		return ;
	ptr = s;
	while (*ptr != '\0')
	{
		(f)(i, ptr++);
		i++;
	}
}
