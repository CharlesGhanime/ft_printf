/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_ouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:29:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/31 17:26:24 by cghanime         ###   ########.fr       */
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
	if (!(str = ft_uintmaxtoa_base(percents->a_t.a_uintmax, base)))
		return (NULL);
	return (str);
}
