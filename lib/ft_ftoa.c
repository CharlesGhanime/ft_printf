/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:11:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/11 15:02:54 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	s1 = ft_strcat(ft_itoa_base(intpart, "0123456789"), ".");
	myfloat -= intpart;
	myfloat *= 100000000;
	decipart = (signed long int)(myfloat);
	if (decipart == 0)
		s2 = ft_strcat(s1, "000000");
	else
		s2 = ft_strcat(s1, ft_itoa_base(decipart, "0123456789"));
//	ft_putstr(s2);
	return (s2);
}

/*
int main()
{
	double myfloat = 42.42;
	double test2 = 420;
	ft_ftoa(myfloat);
	write (1, "\n", 1);
	ft_ftoa(test2);
	return (0);
}

*/
