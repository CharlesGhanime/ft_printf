/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:11:44 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/29 09:01:43 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*addonechar(char **str, char c)
{
	char	*new;
	size_t	size;

	size = 0;
	if (*str)
	{
		size = ft_strlen(*str);
		if (!(new = (char*)malloc(sizeof(char) * size + 2)))
			return (0);
		new = ft_strcpy(new, *str);
		new[size] = c;
		new[size + 1] = '\0';
//		free(*str);
		return (new);
	}
	else
	{
		new = (char*)ft_memalloc(2);
		new[size] = c;
		new[size + 1] = '\0';
		return (new);
	}
	return (NULL);
}

char    *fill_prec(char *str, int diff)
{
	while (diff >= 0)
	{
		ft_addonechar(&str, '0');
		diff--;
	}
	return (str);
}

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
//			free(str);
			if (!(str = (char *)ft_memalloc(ft_strlen(tmp) + 1)))
				return (NULL);
			ft_strcpy(str, tmp);
//			free(tmp);
			//str[i + 1] = '0';
			break ;
		}
		//if (str[i] != '.')
		//	str[i] = '0';
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
//		free(tmp);
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
	if (j < prec)
		return (fill_prec(str, prec - i));
	return (float_prec_flag2(str, i));
}
