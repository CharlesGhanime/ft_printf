/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:11:44 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/16 00:09:36 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*clean_round(char *str, int i)
{
	char *tmp;

	while (str[i])
	{
		if (str[i] != '9' && str[i] != '.')
		{
			str[i] += 1;
			break ;
		}
		if (str[0] == '9' && i == 0)
		{
			tmp = ft_strjoin("1", str);
			free(str);
			if (!(str = (char *)ft_memalloc(ft_strlen(tmp) + 1)))
				return (NULL);
			ft_strcpy(str, tmp);
			free(tmp);
			str[i + 1] = '0';
			break ;
		}
		if (str[i] != '.')
			str[i] = '0';
		i--;
	}
	return (str);
}

char	*float_prec_flag2(char *str, int i)
{
	char	*tmp;

	if ((str[i] - '0') >= 5)
	{
		tmp = str;
		str = clean_round(str, i - 1);
		free(tmp);
		while (str[i])
		{
			str[i] = '0';
			i++;
		}
	}
	return (str);
}

char	*float_prec_flag(char *str, int prec)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i + 1] != '\0' && str[i] != '.')
		i++;
	if (str[i] != '.')
		return (str);
	while (str[i + 1] != '\0' && j < prec)
	{
		i++;
		j++;
	}
	return (float_prec_flag2(str, i));
}
