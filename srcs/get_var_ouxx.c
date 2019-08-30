/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_ouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:29:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/30 15:29:37 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_h_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
		return (NULL);
	return (str);
}

char	*convert_hh_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
		return (NULL);
	return (str);
}

char	*convert_l_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
		return (NULL);
	return (str);
}

char	*convert_ll_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
		return (NULL);
	return (str);
}

char	*get_generic_var(t_ptf *percents, char *base)
{
	char	*str;

	str = NULL;
//	if (percents->flags)
//	{
//		if (percents->flags[0] == 'h' && percents->flags[1] != 'h')
//		{
//			if (!(str = ft_itoa_base(percents->a_t.a_uintmax, base)))
//				return (NULL);
//		}
//		if (percents->flags[0] == 'h' && percents->flags[1] == 'h')
//		{
//			if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
//				return (NULL);
//		}
//		if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
//		{
//			if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
//				return (NULL);
//		}
//		if (percents->flags[0] == 'l' && percents->flags[1] == 'l')
//		{
//			if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
//				return (NULL);
//		}
//	}
//	else
		if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
			return (NULL);
	return (str);
}
