/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:11:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/15 17:38:13 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(double myfloat)
{
	signed long int		intpart;
	signed long int		decipart;
	char				*s1;
	char				*s2;

	s2 = NULL;
	if (myfloat < 1)
	{
		ft_putchar('-');
		myfloat *= -1;
	}
	intpart = (signed long int)myfloat;
	s1 = ft_strcat(ft_itoa_base(intpart, 10), ".");
	myfloat -= intpart;
	myfloat *= 100000000;
	decipart = (signed long int)(myfloat);
	s2 = ft_strcat(s1, ft_itoa_base(decipart, 10));
	ft_putstr(s2);
	return (s2);
}
