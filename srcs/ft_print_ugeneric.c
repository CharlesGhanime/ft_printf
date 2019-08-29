/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ugeneric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:47:53 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/29 09:49:27 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_generic(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = get_generic_var(percents, base)))
		return (FALSE);
	if (percents->precision == -1 && str && str[0] == '0'
	&& !(percents->options & HASH && percents->conv == 'o'))
		str = "";
	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str))))
		return (FALSE);
	if (!(percents->options & HASH))
	{	
		if (!(str = int_width(str, percents->width,
		(long)ft_strlen(str), percents)))
			return (FALSE);
		else
		{
			if (!(str = int_width(str, percents->width,
			(long)ft_strlen(str), percents)))
				return (FALSE);
		}
	}
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
	percents->size = ft_strlen(str);
	ft_putstr(str);
	//free(str);
	return (TRUE);
}

int		ft_print_empty(t_ptf *percents)
{
	char *str;
	int i;

	i = 0;
	str = "\0";
	if (percents->width && !(percents->options & MINUS))
		while (i++ < percents->width - 1)
			percents->options & ZERO ? write(1, "0", 1) : write (1, " ", 1);
	ft_putstr(str);
	if (percents->width && percents->options & MINUS)
		while (i++ < percents->width - 1)
			write(1, " ", 1);
	return (ft_strlen(str) > (size_t)percents->width ? ft_strlen(str) : percents->width);
}

int		ft_print_float_generic(t_ptf *percents)
{
	char *str;

	str = NULL;
//	if (!percents->precision)
//		percents->precision = 6;
//	if (!(str = get_float_generic_var(percents)))
//		return (FALSE);
//	if (!(str = float_prec_flag(str, percents->precision)))
//		return (FALSE);
//	if (!(str = manage_opts(str, percents)))
//		return (FALSE);
//	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
//		return (FALSE);
    
    percents->size = ft_strlen(str);
	ft_putstr(str);
	//	if (str)
	//		free(str);
	return (TRUE);
}
