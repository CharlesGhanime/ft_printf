/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:09:41 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/08 03:05:56 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* PRINT CHAR */

int     ft_print_char(t_ptf *percents)
{
	percents->size = 1;
	ft_putchar((char)percents->a_t.a_int);
	return (TRUE);
}

/* PRINT STRING */

char	*str_width(char *str, long width, t_ptf *percents, char c)
{
	char 	*new;
	char	*tmp;
	int		token;

	tmp = NULL;
//	if (!(new = ft_fillchar(width, (long)ft_strlen(str), c)))
//		return (NULL);
	if (!(tmp = ft_strjoin(new, str)))
		return (NULL);
	new = ft_strdup(tmp);
	free(tmp);
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
	free(str);
	return (new);
}

int     ft_print_string(t_ptf *percents)
{
	char *str;

	if (!(str = ft_strdup(percents->a_t.a_string)))
		return (FALSE);
	if (!(str = str_precision(str, percents->precision)))
		return (FALSE);
	if (!(str = str_width(str, percents->width, percents, ' ')))
		return (FALSE);
	ft_putstr(str);
//  printf(""_RED"%s"_END"", str);
	percents->size = ft_strlen(str);
	free(str);
	return (FALSE);
}
