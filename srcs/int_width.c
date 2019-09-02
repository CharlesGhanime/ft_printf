/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 06:58:28 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/03 00:39:11 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*int_width(char *str, long width, long len, t_ptf *percents)
{
	char	*new;
	char	*padd;
	long	diff;

	diff = width - len;
	if (diff < 0 || !width || (width - 1 == len && percents->options & PLUS
		&& !(percents->unsignd)))
		return (str);
	new = NULL;
	padd = supp_width(str, percents, &diff);
	new = moar_width(str, padd, percents, diff);
	if (!new)
		return (str);
	if (str != NULL && str[0] != '\0')
		free(str);
	return (new);
}

char	*supp_width(char *str, t_ptf *percents, long *diff)
{
	long	len;
	char	*padd;
	int		min;

	padd = NULL;
	min = 0;
	len = (long)ft_strlen(str);
	if ((percents->options & PLUS
				&& (ft_ischar(str, '-') == 0)) || (percents->options & SPACE
				&& percents->options & ZERO && ((percents->width - 2) == len)))
	{
		min = 2;
		*diff -= 1;
	}
	if (percents->options & ZERO && !(percents->precision)
			&& !(percents->options & MINUS))
		padd = ft_padding(*diff, '0');
	else
	{
		if (min == 2 && !(percents->options & MINUS))
			*diff += 1;
		padd = ft_padding(*diff, ' ');
	}
	return (padd);
}

char	*moar_width(char *str, char *padd, t_ptf *percents, long diff)
{
	char	*new;
	int		min;
	long	len;

	new = NULL;
	min = 0;
	len = (long)ft_strlen(str);
	if (!(percents->options & MINUS))
	{
		if (str[0] == '-' && padd && padd[0] == '0')
			min = 1;
		if (!(new = ft_strjoinfrchoz(padd, str, 1)))
			return (NULL);
		if (min == 1)
		{
			new[diff] = '0';
			new[0] = '-';
		}
	}
	else if (percents->width > len)
	{
		if (!(new = ft_strjoinfrchoz(str, padd, 2)))
			return (NULL);
	}
	return (new);
}
