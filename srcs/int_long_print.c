/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_long_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:35:39 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/30 11:59:24 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* PRINT DECIMAL */

char	*get_int_var(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (ft_ischar(percents->flags, 'l') == 1)
	{	
		if (*(percents->flags + 1) == 'l')
		{
			if (!(str = ft_ltoa(percents->a_t.a_intmax)))
				return (NULL);
			percents->a_t.a_intmax >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		}
		else 
		{
			if (!(str = ft_ltoa(percents->a_t.a_intmax)))
				return (NULL);
			percents->a_t.a_intmax >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		}
	}
	else 
	{
		if (!(str = ft_itoa(percents->a_t.a_intmax)))
			return (NULL);
		percents->a_t.a_intmax >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}	
	return (str);
}

char 	*int_precision(char *str, long precision, int len)
{
	char	*new;
	int 	i;
	
	new = NULL;
	if ((!precision || (int)precision < len))
		return (str);
	if (!(new = (char *)malloc(sizeof(char) * (precision + len + 1))))
		return (NULL);
	i = -1;
	if (str[0] == '-')
	{
		new[0] = '-';
		str[0] = '0';
		precision++;
		i++;
	}
	while (++i < ((int)precision - len))
		new[i] = '0';
	new[i] = '\0';
	new = ft_strcat(new, str);
//	free(str);
	return (new);
}

char	*int_width(char *str, long width, long len, t_ptf *percents)
{
	char	*new;
	char	*padd;
	long	diff;
	int		min;

	diff = width - len;
	if (diff < 0 || !width || (width - 1 == len && percents->options & PLUS && !(percents->unsignd)))
		return (str);
	min = 0;
	new = NULL;
	padd = NULL;
	if ((percents->options & PLUS && (ft_ischar(str, '-') == 0)) || (percents->options & SPACE && percents->options & ZERO && width - 2 == len))
	{
		min = 2;
		diff--;
	}

	if (percents->options & ZERO && !(percents->precision) && !(percents->options & MINUS))
		padd = ft_padding(diff, '0'); 
	else
	{
		if (min == 2 && !(percents->options & MINUS))
			diff++;
		padd = ft_padding(diff, ' ');
	}

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
	else if (width > len)
	{
		if (!(new = ft_strjoinfrchoz(str, padd, 2)))
			return (NULL);
	}
//	else if (padd)
//		free(padd);
	if (!new)
		return (str);
//	free(str);
	return (new);
}

int		ft_print_decimal(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (!(str = get_int_var(percents)))
		return (FALSE);
//	printf("ITIZ1 = %s\n", str);
	if (percents->precision == -1 && str && str[0] == '0')
		str = "";
	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str))))
		return (FALSE);
//	printf("ITIZ2 = %s\n", str);
	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
		return (FALSE);
//	printf("ITIZ3 = %s\n", str);
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
//	printf("ITIZ4 = %s\n", str);
  	percents->size = ft_strlen(str);
	ft_putstr(str);
	if (str != NULL || str[0] != '\0')
		free(str);
	return (TRUE);
}
