/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 01:22:28 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/29 22:57:33 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t		ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str)
	{
		while (*str++)
			count++;
	}
	return (count);
}
