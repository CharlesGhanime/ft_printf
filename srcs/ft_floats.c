/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 08:37:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/30 15:07:25 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "../includes/ft_printf.h"
#include <stdio.h>

static double	ft_calc_modulo(double nb, int *size)
{
	double	modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	return (modulo);
}

static void		ft_handle_integer(double *nb, char **str, int *i, double modulo)
{
	char *s;

	s = NULL;
	s = *str;
	while (modulo && (int)*nb)
	{
		s[(*i)++] = (char)((*nb / modulo + 48));
		*nb -= (int)(*nb / modulo) * modulo;
		modulo /= 10;
	}
}

static void		ft_handle_decimals(char **str, int *i, double nb, int precision)
{
	int		j;
	int		tmp;
	char	*s;

	nb *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < precision)
	{
		if ((int)nb == 0)
		{
			s[(*i)++] = '0';
			continue ;
		}
		tmp = ((int)nb != 9) ? (nb + 0.01) : (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}

static char		ft_handle_inf(char **s)
{
	if (!(*s = malloc(sizeof(char) * 4)))
		return (0);
	*s = "inf";
	return (**s);
}

char			*ft_put_float_to_string(double nb, char **s, int precision)
{
	int		i;
	int		size;
	char	*str;
	int		neg;
	double	modulo;

	if (nb == INFINITY)
		return (ft_itoa(ft_handle_inf(s)));
	size = 1;
	neg = 0;
	modulo = 0;
	if (nb < 0 && size++ && (neg = 1) == 1)
		nb = -nb;
	modulo = ft_calc_modulo(nb, &size);
	size += precision;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_handle_integer(&nb, &str, &i, modulo);
	ft_handle_decimals(&str, &i, nb, precision);
	str[--i] = '\0';
	*s = str;
	return (str);
}
