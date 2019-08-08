/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_octal_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:47:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/08 04:32:54 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/* PRINT OCTAL */

int		ft_print_octal(t_ptf *percents)
{
	char *str;

//	percents->size = ft_strlen(ft_itoa(percents->a_t.a_ullong));
	str = ft_itoa_base(percents->a_t.a_ullong, "01234567");
//	ft_hashtag_flag(percents);
//	ft_zero_flag(percents, percents->size);
	ft_putstr(str);
//	ft_minus_flag(percents, percents->size);
	return (TRUE);
}

/* PRINT UNSIGNED */

int		ft_print_unsigned(t_ptf *percents)
{
	char *str;

//	percents->size = ft_strlen(ft_itoa(percents->a_t.a_uint));
	str = ft_itoa_base(percents->a_t.a_ullong, "0123456789");
//	ft_hashtag_flag(percents);
//	ft_zero_flag(percents, percents->size);
	ft_putstr(str);
//	ft_minus_flag(percents, percents->size);
	return (TRUE);
}

/* PRINT HEXA */

int		ft_print_hexa(t_ptf *percents)
{
	char *str;

//	percents->size = ft_strlen(ft_itoa(percents->a_t.a_ullong));
	str = ft_itoa_base(percents->a_t.a_ullong, "0123456789abcdef");
//	ft_hashtag_flag(percents);
//	ft_zero_flag(percents, percents->size);
	ft_putstr(str);
//	ft_minus_flag(percents, percents->size);
	return (TRUE);
}

/* PRINT HEXA MAJ */

int		ft_print_hexa_maj(t_ptf *percents)
{
	char *str;

//	percents->size = ft_strlen(ft_itoa_base(percents->a_t.a_ullong, "0123456789ABCDEF"));
	str = ft_itoa_base(percents->a_t.a_ullong, "0123456789ABCDEF");
//	ft_hashtag_flag(percents);
//	ft_zero_flag(percents, percents->size);
	ft_putstr(str);
//	ft_minus_flag(percents, percents->size);
	//ft_putstr(ft_width_precision(str, percents, percents->size));
	return (TRUE);
}

/* PRINT FLOAT */

int		ft_print_float(t_ptf *percents)
{
	char *str;
	int i;

	i = 0;
	str = ft_ftoa(percents->a_t.a_ldouble);

	if (!percents->precision)
		percents->precision = 6;
	if (percents->precision)
		if (str[percents->precision] > 5 + '0')
		{
			str[i] = 0 + '0';
			str[i - 1] += 1 + '0';
		}
	ft_strncat(str, "\0", percents->precision + 1);
	ft_putstr(str);
	return (TRUE);
}
