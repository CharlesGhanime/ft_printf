/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:50:58 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/22 14:49:18 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_pad(t_ptf *percents)
{
	int width;

	if (percents->width < 0)
		return (percents->size);
	width = 0;
	while (width++ < percents->width - percents->size)
	{
		write(1, ((percents->options & ZERO) 
					&& !(percents->options & MINUS)) ? "0" : " ", 1);
	}
	return (percents->size + percents->width - 1);
}

void ft_write(char c, int size)
{
	int i = 0;
	while (i++ < size)
		write(1, &c, 1);
}

int		ft_handle_precision(t_ptf *percents, int size)
{
	if (!percents->precision)
	{
		if (percents->conv == 'f')
			percents->precision = 6;
		else
			percents->precision = 1;
	}
	if (size < percents->precision || size < percents->width)
	{
		if (percents->precision >= percents->width)
		{
			ft_write('0', (int)(percents->precision - size));
			return (percents->precision);
		}
		if (percents->precision < percents->width)
		{
			ft_write(' ', (int)(percents->width - size));
			size = percents->precision;
			return (percents->width);
		}
	}
	else
		return (size);
	return (0);
}

/* precision est plus grande que width et size : affiche et return precision
 * precision est plus petite que width : affiche width - precision - size
 * size > precision : on tronque le nombre a la taille de precision
 *
 *
 *
 *
 */

/*
int main ()
{
	t_ptf *coucou;
	coucou = init_head(coucou);
	coucou->conv ='x';
	coucou->precision=10;
	coucou->width=30;
	coucou->size=10;
	int ret = 0;
	char *s = "12345678901234567890";
	int i= 1001199211;
	ret = ft_handle_precision(coucou);
	//	write(1, "12345678901234567890\n", coucou->size);
	ft_putstr(ft_itoa(i));
}
*/
