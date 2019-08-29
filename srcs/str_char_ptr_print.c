/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_ptr_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:09:41 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/29 00:51:53 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(t_ptf *percents)
{
	int i;

	i = 0;
	percents->size = 1;
	if (percents->width > 1 && !(percents->options & MINUS))
		while (i++ < percents->width - 1)
			(percents->options & ZERO) ? write(1, "0", 1) : write(1, " ", 1);
	ft_putchar((char)percents->a_t.a_intmax);
	if (percents->width > 1 && percents->options & MINUS)
		while (i++ < percents->width - 1)
			(percents->options & ZERO) ? write(1, "0", 1) : write(1, " ", 1);
	if (percents->width)
		percents->size = percents->width;
	else
		percents->size = 1;
	return (TRUE);
}

int		ft_print_percent(t_ptf *percents)
{
	int i;

	i = 0;
	percents->size = 1;
	if (percents->width > 1 && !(percents->options & MINUS))
		while (i++ < percents->width - 1)
			(percents->options & ZERO) ? write(1, "0", 1) : write(1, " ", 1);
	ft_putchar((char)percents->a_t.a_intmax);
	if (percents->width > 1 && percents->options & MINUS)
		while (i++ < percents->width - 1)
			(percents->options & ZERO) ? write(1, "0", 1) : write(1, " ", 1);
	if (percents->width)
		percents->size = percents->width;
	else
		percents->size = 1;
	return (TRUE);
}

char	*str_width(char *str, long width, t_ptf *percents, char c)
{
	char	*new;
	char	*padd;
	long	diff;

	new = NULL;
	diff = width - (long)ft_strlen(str);
	if (diff < 0)
		return (str);
	padd = NULL;
	if (!(padd = ft_padding(diff, c)))
		return (NULL);
	if (!padd)
		return (str);
	if (diff > 0 && !(percents->options & MINUS))
	{
		if (!(new = ft_strjoinfrchoz(padd, str, 1)))
			return (NULL);
	}
	else if (percents->width < -1 || percents->options & MINUS)
		if (!(new = ft_strjoinfrchoz(str, padd, 2)))
			return (NULL);
	if (padd)
		free(padd);
	if (!new)
		return (str);
	return (new);
}

char	*str_precision(char *str, long precision)
{
	char	*new;
	int		i;

	if (!precision || (long)ft_strlen(str) < precision)
		return (str);
	if (!(new = (char *)malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	i = -1;
	while (str[++i] && i < (int)precision)
		new[i] = str[i];
	new[i] = '\0';
//	free(str);
	return (new);
}

int		ft_print_string(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (!(str = ft_strdup(percents->a_t.a_string)))
		return (FALSE);
	if (!(str = str_precision(str, percents->precision)))
		return (FALSE);
	if (percents->options & ZERO)
	{
		if (!(str = str_width(str, percents->width, percents, '0')))
			return (FALSE);
	}
	else
	{
		if (!(str = str_width(str, percents->width, percents, ' ')))
			return (FALSE);
	}
//	if (str == NULL)
//		str = "(null)";
	ft_putstr(str);
	percents->size = ft_strlen(str);
	free(str);
	return (FALSE);
}
