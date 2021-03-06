/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ugeneric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:47:53 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 23:12:58 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_generic(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = get_generic_var(percents, base)))
		return (FALSE);
	if (percents->precision == -1 && str && str[0] == '0'
	&& !(percents->options & HASH && percents->conv == 'o'))
		str = "";
	if (percents->options & HASH && percents->conv == 'o')
		percents->precision -= 1;
	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str))))
		return (FALSE);
	if (!(percents->options & HASH))
	{
		if (!(str = int_width(str, percents->width,
		(long)ft_strlen(str), percents)))
			return (FALSE);
	}
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
	percents->size = ft_strlen(str);
	ft_putstr(str);
	if (str != NULL && str[0] != '\0')
		free(str);
	return (TRUE);
}

int		ft_print_empty(t_ptf *percents)
{
	char	*str;
	int		i;

	i = 0;
	str = "\0";
	if (percents->width && !(percents->options & MINUS))
		while (i++ < percents->width - 1)
			percents->options & ZERO ? write(1, "0", 1) : write(1, " ", 1);
	ft_putstr(str);
	if (percents->width && percents->options & MINUS)
		while (i++ < percents->width - 1)
			write(1, " ", 1);
	return (ft_strlen(str) > (size_t)percents->width ?
	ft_strlen(str) : percents->width);
}

char	*ft_manage_floats(t_ptf *percents, char *str)
{
	if (!((int)percents->a_t.a_ldouble))
		str = ft_addonecharpos(&str, '0', 0);
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
	(percents->a_t.a_ldouble > 0) ? percents->signe = '+' : '-';
	if ((percents->options & PLUS) && !(percents->options & SPACE))
		str = ft_addonecharpos(&str, percents->signe, 0);
	if (!(percents->options & PLUS) && (percents->options & SPACE)
	&& percents->signe == '+')
		str = ft_addonecharpos(&str, ' ', 0);
	if (!(str = int_width(str, percents->width, (long)ft_strlen(str),
	percents)))
		return (FALSE);
	return (str);
}

int		ft_print_float_generic(t_ptf *percents)
{
	char *str;
	char *s;

	str = NULL;
	s = NULL;
	if (!percents->precision)
		percents->precision = 6;
	if (!(str = ft_put_float_to_string(percents->a_t.a_ldouble,
	&s, percents->precision)))
		return (FALSE);
	if (!(str = ft_manage_floats(percents, str)))
		return (FALSE);
	percents->size = ft_strlen(str);
	ft_putstr(str);
	if (str != '\0')
		free(str);
	return (TRUE);
}
