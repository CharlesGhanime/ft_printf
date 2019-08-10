/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 00:39:23 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/10 21:03:20 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_pos(char *str)
{
	int		pos;

	pos = 0;
	while (str[pos + 1] == ' ')
		pos++;
	return (pos);
}

char	*manage_opts(char *str, t_ptf *percents)
{
	int     pos;
	char    *new;

	new = NULL;
	if (percents->options & HASH && (percents->conv == 'x' || percents->conv == 'X'
				|| percents->conv == 'o') && !(str[0] == '0' && percents->conv == 'o'))
		new = ft_hashtag_flag(percents, str);
	if (percents->options & SPACE && !(percents->options & PLUS) &&
			!(percents->unsignd) && (percents->signe == '+' || !str) && str[0] != ' ')
		new = ft_addonecharpos(&str, ' ', 0);
	if (percents->options & PLUS && !(percents->unsignd) && (ft_ischar(str, '-') == 0))
	{
		if (str[0] == ' ')
		{
			pos = count_pos(str);
			str[pos] = percents->signe;
		}
		else if (str[0] != '-')
			new = ft_strjoinfrchoz(&percents->signe, str, 2);
	}
	if (!new)
		return (str);
	return (new);
}

