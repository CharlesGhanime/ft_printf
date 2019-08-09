/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:09:41 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/09 05:38:33 by aboitier         ###   ########.fr       */
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
	char	*padd;
	long	diff;

	diff = width - (long)ft_strlen(str);
	if (diff < 0)
		return (str);
	padd = NULL;
	if (!(padd = ft_padding(diff, c)))
		return (NULL);
		
	//printf("ITIZp == %s\n", padd);
	//printf("ITIZs == %s\n", str);
	if (!padd)
		return (str);
	if (diff > 0 && percents->options & MINUS)
	{
		//printf("ITIZn == %s\n", new);
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
	free(str);
	return (new);
}

int     ft_print_string(t_ptf *percents)
{
	char *str;

	str = NULL;
	//printf("ITIZB == %s\n", str);
	if (!(str = ft_strdup(percents->a_t.a_string)))
		return (FALSE);
	//printf("ITIZ1 == %s\n", str);
	if (!(str = str_precision(str, percents->precision)))
		return (FALSE);
	//printf("ITIZ2 == %s\n", str);
	if (!(str = str_width(str, percents->width, percents, ' ')))
		return (FALSE);
	//printf("ITIZ3 == %s\n", str);
	ft_putstr(str);
	//  //printf(""_RED"%s"_END"", str);
	percents->size = ft_strlen(str);
	free(str);
	return (FALSE);
}


/* PRINT ADDRESS */

int     ft_print_address(t_ptf *percents)
{
	char *str;

	if (!(str = ft_strdup(ft_itoa_base((long)percents->a_t.a_ptr, "0123456789abcdef"))))
		return (FALSE);
	//  //printf("retour de ft_itoa_base = %s\n", str);
	//  //printf("\nstr = %s\n", str);
	//  //printf("//printf prog = %p\n", percents->a_t.a_ptr);
	percents->size = ft_strlen(str) + 2;
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
	return (TRUE);
}

