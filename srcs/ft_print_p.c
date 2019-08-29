/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:23:09 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/29 06:40:49 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_hashtag_p(t_ptf *percents, char *str)
{
	char	*width;
	char	*hash;

	width = NULL;
	hash = NULL;
	if (percents->options & ZERO)
	{
		width = int_width(str, percents->width - 2, (long)ft_strlen(str),
				percents);
		hash = ft_strjoin("0x", width);
//		free(width);
		return (hash);
	}
	if (!(percents->options & ZERO))
	{
		hash = ft_strjoin("0x", str);
		width = int_width(hash, percents->width, (long)ft_strlen(hash),
				percents);
//		free(hash);
		return (width);
	}
	return (str);
}

int		ft_print_address(t_ptf *percents)
{
	char *str;
	char *base;

	str = NULL;
	base = "0123456789abcdef";
	if (percents->precision == -1 && !(percents->a_t.a_ptr))
		str = "0x";
	else 
		if (!(str = ft_uintmaxtoa_base((uintmax_t)percents->a_t.a_ptr,
		base)))
		return (FALSE);
	if (!(str = int_precision(str, percents->precision, (long)ft_strlen(str))))
		return (FALSE);
	if (percents->precision != -1)
		if (!(str = ft_strjoin("0x", str)))
			return (FALSE);
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
		return (FALSE);
	percents->size = ft_strlen(str);
	ft_putstr(str);
//	free(str);
	return (TRUE);
}

int		ft_print_invalid(t_ptf *percents)
{
	char	*str;

	str	= NULL;

	if (percents->reste)	
		if (!(str = ft_strdup(percents->reste)))
			return (FALSE);
	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
		return (FALSE);
	percents->size = ft_strlen(str);
	return (TRUE);
}
