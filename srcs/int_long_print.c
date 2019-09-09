/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_long_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:35:39 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 23:25:23 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_int_var(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (ft_ischar(percents->flags, 'l') == 1)
	{
		if (!(str = ft_ltoa(percents->a_t.a_intmax)))
			return (NULL);
		percents->a_t.a_intmax >= 0 ? (percents->signe = '+')
			: (percents->signe = '-');
	}
	else
	{
		if (!(str = ft_itoa(percents->a_t.a_intmax)))
			return (NULL);
		percents->a_t.a_intmax >= 0 ? (percents->signe = '+')
			: (percents->signe = '-');
	}
	return (str);
}

char	*int_precision(char *str, long precision, int len)
{
	char	*new;
	int		i;

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
	free(str);
	return (new);
}

int		ft_print_decimal(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (!(str = get_int_var(percents)))
		return (FALSE);
	if (percents->precision == -1 && str && str[0] == '0')
	{
		free(str);
		str = "";
	}
	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str))))
		return (FALSE);
	if (!(str = int_width(str, percents->width,
					(long)ft_strlen(str), percents)))
		return (FALSE);
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
	percents->size = ft_strlen(str);
	ft_putstr(str);
	if (str != NULL && str[0] != '\0')
		free(str);
	return (TRUE);
}
