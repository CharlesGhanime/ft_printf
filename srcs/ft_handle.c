/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:50:58 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/15 12:26:57 by cghanime         ###   ########.fr       */
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

int		ft_handle_precision(t_ptf *percents)
{
	if (!percents->precision)
	{
		if (percents->conv == 'f')
			percents->precision = 6;
		else
			percents->precision = 1;
	}
	if (percents->precision >= percents->width
	&& percents->precision > percents-> size)
	{
		ft_write('0', (int)(percents->precision - percents->size));
		return (percents->precision);
	}
	if (percents->precision <= percents->width
	&& percents->width > percents->size)
	{
		ft_write(' ', (int)(percents->width - percents->precision));
		percents->size = percents->precision;
		return (percents->width);
	}
	else
		return (percents->size);
}

int main ()
{
	t_ptf *coucou;
	coucou = init_head(coucou);
	coucou->conv ='x';
	coucou->precision=10;
	coucou->width=10;
	coucou->size=20;
	int ret = 0;
	char *s = "12345678901234567890";
	int i= 10011992;
	ret = ft_handle_precision(coucou);
//	write(1, "12345678901234567890\n", coucou->size);
	ft_itoa(i);
	printf("\n");
	printf("%10.10d\n", i);
	printf("ret = %d", ret);
}
