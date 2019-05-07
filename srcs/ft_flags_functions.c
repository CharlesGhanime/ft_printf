/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:08:49 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/07 18:49:24 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*J'ai besoin de recuperer la liste chainee en argument*/

/* je vais utiliser le char *option
 * que je dois parcourir pour savoir
 * si j'ai l'option "-", "+" etc*/

void	ft_minus_flag(va_list arg, t_ptf *word)
{
	int i;

	i = 0;

	while (word->options[i])
	{
		if (word->conv == 'c')
		{
			if (word->options[i] == '-')
				if (word->width && !word->precision)
				{
					while (i != (word->width - 1))
					{
						ft_putchar(' ');
						i++;
					}
//				s1 = (char *)malloc(sizeof(char) * word->width + 1);
//				ft_memset(s1, ' ', ft_strlen(s1));
				}
				if ((!word->width && word->precision) || (word->width <= word->precision))
				{
					while (i != (word->precision - 1))
					{
						ft_putchar(' ');
						i++;
					}
//				s1 = (char *)malloc(sizeof(char) * word->width + 1);
//				ft_memset(s1, ' ', ft_strlen(s1));
				}
				if (word->width && word->precision)
				{
					while (i != (word->width - word->precision - 1))
					{
						ft_putchar(' ');
						i++;
					}
//				s1 = (char *)malloc(sizeof(char) * word->width + 1);
//				ft_memset(s1, ' ', ft_strlen(s1));
				}
		}
	i++;
	}
}

void	ft_plus_flag(va_list arg, t_ptf *word)
{
	int i;

	i = 0;
	while (word->options[i])
	{
		if (word->options[i] == '+')
			if (va_arg(arg, int) >= 0 || va_arg(arg, double) >= 0)
				ft_putchar('+');
	}
}

void	ft_hashtag_flag(va_list arg, t_ptf *word)
{

}

void	ft_zero_flag(va_list arg, t_ptf *word)
{

}
char	*ft_float_precision_flag(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] >= 5)
	{
		str[i] = '0';
		str[i - 1] += 1;
	}
	return (str);
}
