/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 00:39:23 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/30 16:44:49 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		count_pos(char *str)
{
	int		pos;

	pos = 0;
	while (str[pos + 1] == ' ')
		pos++;
	return (pos);
}

char			*manage_opts(char *str, t_ptf *percents)
{
	int		pos;
	char	*new;

	new = NULL;
	pos = 0;
	if (percents->options & HASH && (percents->conv == 'x'
				|| percents->conv == 'X' || percents->conv == 'o')
			&& !(str[0] == '0' && percents->conv == 'o'))
		new = ft_hashtag_flag(percents, str);
	if (percents->options & SPACE && !(percents->options & PLUS) && !(percents->unsignd)
			&& (percents->signe == '+' || !str) && str && str[0] != ' ')
		new = ft_addonecharpos(&str, ' ', 0);
	if (percents->options & PLUS && !(percents->unsignd)
			&& (ft_ischar(str, '-') == 0))
	{
		if (str[0] == ' ')
		{
			pos = count_pos(str);
			str[pos] = percents->signe;
		}
		else
			new = ft_addonecharpos(&str, percents->signe, 0);
	}
	if (!new)
		return (str);
	return (new);
}

char			*supp_width(char *str, t_ptf *percents, long *diff)
{
	long	len;
	char	*padd;
	int		min;

	padd = NULL;
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

char			*moar_width(char *str, char *padd, t_ptf *percents, long diff)
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
