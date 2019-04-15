/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:26:37 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/15 13:02:58 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		entier;
	int		signe;

	i = 0;
	entier = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		signe = str[i++] == '-' ? -1 : 1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		entier = entier * 10 + (str[i] - '0');
		i++;
	}
	return (entier * signe);
}
