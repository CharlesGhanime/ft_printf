/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:08:49 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/31 17:23:15 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_hashtag_o(t_ptf *percents, char *str)
{
	char	*width;
	char	*hash;

	width = NULL;
	hash = NULL;
	if (percents->options & ZERO)
	{
		width = int_width(str, percents->width - 1, (long)ft_strlen(str),
		percents);
		hash = ft_strjoinfrchoz("0", width, 2);
		return (hash);
	}
	if (!(percents->options & ZERO))
	{
		hash = ft_strjoinfrchoz("0", str, 2);
		width = int_width(hash, percents->width, (long)ft_strlen(hash),
				percents);
		return (width);
	}
	return (str);
}

char	*ft_hashtag_x(t_ptf *percents, char *str)
{
	char	*width;
	char	*hash;

	width = NULL;
	hash = NULL;
	if (percents->options & ZERO && percents->precision == 0)
	{
		width = int_width(str, percents->width - 2, (long)ft_strlen(str),
				percents);
		hash = ft_strjoinfrchoz("0x", width, 2);
		return (hash);
	}
	if (!(percents->options & ZERO) || (percents->options & ZERO
	&& percents->precision != 0))
	{
		hash = ft_strjoinfrchoz("0x", str, 2);
		width = int_width(hash, percents->width, (long)ft_strlen(hash),
				percents);
		return (width);
	}
	return (str);
}

char	*ft_hashtag_cap_x(t_ptf *percents, char *str)
{
	char	*width;
	char	*hash;

	width = NULL;
	hash = NULL;
	if (percents->options & ZERO && percents->precision == 0)
	{
		width = int_width(str, percents->width - 2, (long)ft_strlen(str),
				percents);
		hash = ft_strjoinfrchoz("0X", width, 2);
		return (hash);
	}
	if (!(percents->options & ZERO) || (percents->options & ZERO
		&& percents->precision != 0))
	{
		hash = ft_strjoinfrchoz("0X", str, 2);
		width = int_width(hash, percents->width, (long)ft_strlen(hash),
				percents);
		return (width);
	}
	return (str);
}

char	*ft_hashtag_flag(t_ptf *percents, char *str)
{
	char		*buff;

	buff = NULL;
	if (percents->a_t.a_uintmax != 0)
	{
		if (percents->conv == 'o')
			buff = ft_hashtag_o(percents, str);
		if (percents->conv == 'x')
			buff = ft_hashtag_x(percents, str);
		if (percents->conv == 'X')
			buff = ft_hashtag_cap_x(percents, str);
		return (buff);
	}
	else
	{
		buff = int_width(str, percents->width, (long)ft_strlen(str), percents);
		return (buff);
	}
}
