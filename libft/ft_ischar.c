/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:44:45 by aboitier          #+#    #+#             */
/*   Updated: 2019/06/25 07:03:44 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_ischar(char *str, char c)
{
	int i;

	printf("str === %s\n", str);
	i = -1;
	if (str)
	{	
		while (str[++i])
			if (str[i] == c)
			{
				printf("\nstr[i] = %c\n", str[i]);
				return (1);
			}
	}
	return (0);
}
