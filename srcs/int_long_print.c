/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff_reforged.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:35:39 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/09 00:57:15 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/* PRINT DECIMAL */

char	*get_int_var(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (ft_ischar(percents->flags, 'l') == 1)
	{	
		if (*(percents->flags + 1) == 'l')
		{
			if (!(str = ft_ltoa(percents->a_t.a_llong)))
				return (NULL);
			percents->a_t.a_llong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		}
		else 
		{
			if (!(str = ft_ltoa(percents->a_t.a_long)))
				return (NULL);
			percents->a_t.a_long >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		}
	}
	else 
	{
		if (!(str = ft_itoa(percents->a_t.a_int)))
			return (NULL);
		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}	
	return (str);
}

//char	*str_width(char *str, long width, t_ptf *percents, char c)
//{
//	char 	*new;
//	char	*tmp;
//	int 	token;
//
//	tmp = NULL;
////	if (!(new = ft_fillchar(width, (long)ft_strlen(str), c)))
////		return (NULL);
////	token = get_token(percents);
////	if (token == 0)
////	{
//		if (!(tmp = ft_strjoin(new, str)))
//			return (NULL);
////	}
////	else if (token == 1)
////		if (!(tmp = ft_strjoin(str, new)))
////			return (NULL);
//	free(new);
//	new = ft_strdup(tmp);
//	free(tmp);
//	return (new);
//}	

char 	*int_precision(char *str, long precision, int len, t_ptf *percents)
{
	char	*new;
	int 	i;
	
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

char	*int_width(char *str, long width, long len, t_ptf *percents)
{
	char	*new;
	char	*padd;
	long	diff;
	int		min;

	diff = width - len;
	if (diff < 0 || !width || (width - 1 == len && percents->options & PLUS))
		return (str);
	min = 0;
	new = NULL;
	if (percents->options & ZERO && !(percents->precision) && !(percents->options & MINUS))
		padd = ft_padding(diff, '0'); 
	else
		padd = ft_padding(diff, ' ');
//	printf("ITIZs == %s\n", new);
//	printf("LEN === %ld\tWIDTH === %ld\n", len, width);
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
	else if (padd)
		free(padd);
	if (!new)
		return (str);
	free(str);
	return (new);
}

int		ft_print_decimal(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (!(str = get_int_var(percents)))
		return (FALSE);
//	printf("\nITIZ == %s\n", str); 
	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str), percents)))
	   return (FALSE);
//	printf("\nITIZ2 == %s\n", str); 
	if (!(str = int_width(str, percents->width, (long)ft_strlen(str), percents)))
		return (FALSE);
//	printf("\nITIZ3 == %s\n", str); 
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
//	printf("\nITIZ4 == %s\n", str); 
  	percents->size = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (TRUE);
}
