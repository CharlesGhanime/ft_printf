/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_ouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 02:29:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/10 02:57:06 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

char	*get_octal_var(t_ptf *percents)
{
	char	*str;

	str = NULL;
	if (percents->flags)
	{
		if (percents->flags[0] == 'h' && percents->flags[1] != 'h')
			if(!(str = ft_itoa_base(percents->a_t.a_int, "01234567")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'h' && percents->flags[1] == 'h')
			if (!(str = ft_itoa_base(percents->a_t.a_int, "01234567")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ulong, "01234567")))
				return(NULL);
			percents->a_t.a_ulong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] == 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ullong, "01234567")))
				return(NULL);
			percents->a_t.a_ullong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}
	else
		if(!(str = ft_itoa_base(percents->a_t.a_uint, "01234567")))
			return (NULL);
		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}

char	*get_unsigned_var(t_ptf *percents)
{
	char	*str;

	str = NULL;
	if (percents->flags)
	{
		if (percents->flags[0] == 'h' && percents->flags[1] != 'h')
			if(!(str = ft_itoa_base(percents->a_t.a_int, "0123456789")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'h' && percents->flags[1] == 'h')
			if (!(str = ft_itoa_base(percents->a_t.a_int, "0123456789")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ulong, "0123456789")))
				return(NULL);
			percents->a_t.a_ulong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] == 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ullong, "0123456789")))
				return(NULL);
			percents->a_t.a_ullong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}
	else
		if(!(str = ft_itoa_base(percents->a_t.a_uint, "0123456789")))
			return (NULL);
		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}
char	*get_hexa_var(t_ptf *percents)
{
	char	*str;

	str = NULL;
	if (percents->flags)
	{
		if (percents->flags[0] == 'h' && percents->flags[1] != 'h')
			if(!(str = ft_itoa_base(percents->a_t.a_int, "0123456789abcdef")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'h' && percents->flags[1] == 'h')
			if (!(str = ft_itoa_base(percents->a_t.a_int, "0123456789abcdef")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ulong, "0123456789abcdef")))
				return(NULL);
			percents->a_t.a_ulong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] == 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ullong, "0123456789abcdef")))
				return(NULL);
			percents->a_t.a_ullong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}
	else
		if(!(str = ft_itoa_base(percents->a_t.a_uint, "0123456789abcdef")))
			return (NULL);
		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}

char	*get_hexa_maj_var(t_ptf *percents)
{
	char	*str;

	str = NULL;
	if (percents->flags)
	{
		if (percents->flags[0] == 'h' && percents->flags[1] != 'h')
			if(!(str = ft_itoa_base(percents->a_t.a_int, "0123456789ABCDEF")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'h' && percents->flags[1] == 'h')
			if (!(str = ft_itoa_base(percents->a_t.a_int, "0123456789ABCDEF")))
				return (NULL);
			percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] != 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ulong, "0123456789ABCDEF")))
				return(NULL);
			percents->a_t.a_ulong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		if (percents->flags[0] == 'l' && percents->flags[1] == 'l')
			if(!(str = ft_itoa_base(percents->a_t.a_ullong, "0123456789ABCDEF")))
				return(NULL);
			percents->a_t.a_ullong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}
	else
		if(!(str = ft_itoa_base(percents->a_t.a_uint, "0123456789ABCDEF")))
			return (NULL);
		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	return (str);
}
