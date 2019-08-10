/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_ouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:29:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/10 23:35:45 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

char	*convert_h_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if(!(str = ft_itoa_base(percents->a_t.a_int, base)))
		return (NULL);
//	percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}

char	*convert_hh_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if (!(str = ft_itoa_base(percents->a_t.a_int, base)))
		return (NULL);
//	percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}


char	*convert_l_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if(!(str = ft_itoa_base(percents->a_t.a_ulong, base)))
		return(NULL);
//	percents->a_t.a_ulong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}


char	*convert_ll_and_signs(t_ptf *percents, char *base)
{
	char *str;

	str = NULL;
	if(!(str = ft_itoa_base(percents->a_t.a_ullong, base)))
		return(NULL);
//	percents->a_t.a_ullong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}
/*
   char	*get_generic_var(t_ptf *percents, char *base)
   {
   char	*str;

   str = NULL;
   if (percents->flags)
   {
 *		if (percents->flags[0] == 'h' && percents->flags[1] != 'h')
 if (!(str = convert_h_and_signs(percents, base)))
 return (NULL);
 if (percents->flags[0] == 'h' && percents->flags[1] == 'h')
 if (!(str = convert_hh_and_signs(percents, base)))
 return (NULL);
 if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
 if (!(str = convert_l_and_signs(percents, base)))
 return (NULL);
 if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
 if (!(str = convert_ll_and_signs(percents, base)))
 return (NULL);
 }
 else
 {
 if(!(str = ft_itoa_base(percents->a_t.a_uint, base)))
 return (NULL);
 percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
 }
 return (str);
 }
 */

char	*get_generic_var(t_ptf *percents, char *base)
{
	char	*str;

	str = NULL;
	if (percents->flags)
	{
		if (percents->flags[0] == 'h' && percents->flags[1] != 'h')
			if(!(str = ft_itoa_base(percents->a_t.a_int, base)))
				return (NULL);
//		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'h' && percents->flags[1] == 'h')
			if (!(str = ft_itoa_base(percents->a_t.a_int, base)))
				return (NULL);
//		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ulong, base)))
				return(NULL);
//		percents->a_t.a_ulong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] == 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ullong, base)))
				return(NULL);
//		percents->a_t.a_ullong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}
	else
		if(!(str = ft_itoa_base(percents->a_t.a_uint, base)))
			return (NULL);
//	percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}
