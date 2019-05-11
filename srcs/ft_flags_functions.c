/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:08:49 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/08 16:53:46 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*J'ai besoin de recuperer la liste chainee en argument*/

/* je vais utiliser le char *option
 * que je dois parcourir pour savoir
 * si j'ai l'option "-", "+" etc */

/* Solution en stockant tout dans des strings :
 *				s1 = (char *)malloc(sizeof(char) * percents->width + 1);
 *				ft_memset(s1, ' ', ft_strlen(s1)); */

/* ft_counter(va_arg(arg, int)) mais ca ne marchera ps en cas general
 * pour string donc il vaut mieux declarer un int en amont le prendre en
 * parametre : int = ft_counter pour les nombres et ft_strlen pour les string */

void	ft_minus_flag(va_list arg, t_ptf *percents, int nb)
{
    int i;

    i = 0;

    while (percents->options[i])
    {
        if (percents->options[i] == '-')
            if (percents->width && !percents->precision)
            {
                while (i != (percents->width - nb))
                {
                    ft_putchar(' ');
                    i++;
                }
            }
        if ((!(percents->width) && (percents->precision)) || ((percents->width) <= (percents->precision)))
        {
            while (i != (percents->precision - nb))
            {
                ft_putchar(' ');
                i++;
            }
        }
        if (percents->width && percents->precision)
        {
            while (i != (percents->width - percents->precision - nb))
            {
                ft_putchar(' ');
                i++;
            }
        }
        i++;
    }
}

void	ft_plus_flag(va_list arg, t_ptf *percents)
{
    int i;

    i = 0;
    while (percents->options[i])
    {
        if (percents->options[i] == '+')
            if (va_arg(arg, int) >= 0 || va_arg(arg, double) >= 0)
        ft_putchar('+');
    }
}

void	ft_hashtag_flag(va_list arg, t_ptf *percents)
{
    if (percents->conv == o)
        ft_putchar('0');
    if (percents->conv == x)
        ft_putstr("0x");
    if (percents->conv == X)
        ft_putstr("0X");
}

void	ft_zero_flag(va_list arg, t_ptf *percents, int nb)
{
    int i;

    i = 0;

    while (percents->options[i])
    {
        if (percents->options[i] == '0')
            if (percents->width && !percents->precision)
            {
                while (i != (percents->width - nb))
                {
                    ft_putchar('0');
                    i++;
                }
            }
        if ((!percents->width && percents->precision) || (percents->width <= percents->precision))
        {
            while (i != (percents->precision - nb))
            {
                ft_putchar('0');
                i++;
            }
        }
        if (percents->width && percents->precision)
        {
            while (i != (percents->width - percents->precision - nb))
            {
                ft_putchar('0');
                i++;
            }
        }
        i++;
    }
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

void    ft_width_precision(va_list arg, t_ptf *percents, int nb)
{
    while(*(percent->options++))
        if (percents->options != '-' && percents->option != '0')
            if ()
}
