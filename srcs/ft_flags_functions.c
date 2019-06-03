/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:08:49 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/03 12:05:43 by cghanime         ###   ########.fr       */
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
 * pour string donc il vaut mieux declarer un size_t en amont le prendre en
 * parametre : size_t = ft_counter pour les nombres et ft_strlen pour les string */


void	ft_minus_flag(t_ptf *percents, size_t nb)
{
    size_t i;

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
    size_t i;

    i = 0;
    while (percents->options[i])
    {
        if (percents->options[i] == '+')
            if (va_arg(arg, int) >= 0 || va_arg(arg, double) >= 0)
        ft_putchar('+');
    }
}

void	ft_hashtag_flag(t_ptf *percents)
{
    if (percents->conv == 'o')
        ft_putchar('0');
    if (percents->conv == 'x')
        ft_putstr("0x");
    if (percents->conv == 'X')
        ft_putstr("0X");
}


void	ft_zero_flag(t_ptf *percents, size_t nb)
{
    size_t i;

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
    size_t i;

    i = 0;
    while (str[i + 1] != '\0')
        i++;
    if (ft_atoi(&str[i]) >= 5)
    {
        str[i] = 0 + '0';
        str[i - 1] += 1 + '0';
        printf("str[i] = %c\n", str[i]);
    }
    return (str);
}


char    *ft_width_precision(char *src, t_ptf *percents, size_t nb)
{
    size_t i;
    size_t minus;
    size_t zero;
    char *width;
    char *precision;
    char *wp;
    char *final;

    i = 0;
    minus = 0;
    zero = 0;
    while (i <= ft_strlen(percents->options)) {
        if (percents->options[i] == '-')
            minus = 1;
        if (percents->options[i] == '0')
            zero = 1;
        i++;
    }
    if (!percents->precision && percents->conv != 'f')
        percents->precision = 1;
    else
        percents->precision = 6;

    /* FONCTION DE GESTION DE WIDTH PRECISION MINUS ET ZERO */

        if (percents->width > nb) {
            if (percents->precision > nb) {
                if (percents->width > percents->precision) {
                    if (minus) {
                        width = (char *) malloc(sizeof(char) * (percents->width - percents->precision + 1));
                        ft_memset(width, ' ', ft_strlen(width));
                        precision = (char *) malloc(sizeof(char) * (percents->precision - nb + 1));
                        ft_memset(precision, '0', ft_strlen(precision));
                        wp = ft_strjoin(precision, src);
                        return (final = ft_strjoin(src, width));
                    } else {
                        width = (char *) malloc(sizeof(char) * (percents->width - percents->precision + 1));
                        wp = (char *) malloc(sizeof(char) * percents->width + 1);
                        ft_memset(width, ' ', ft_strlen(width));
                        precision = (char *) malloc(sizeof(char) * (percents->precision - nb + 1));
                        ft_memset(precision, '0', ft_strlen(precision));
                        wp = ft_strjoin(width, precision);
                        return (final = ft_strjoin(wp, src));
                    }
                }
                if (percents->width < percents->precision) {
                    precision = (char *) malloc(sizeof(char) * (percents->precision - nb + 1));
                    ft_memset(precision, '0', ft_strlen(precision));
                    return (final = ft_strjoin(precision, src));
                }
            }
            if (!percents->precision) {
                if (zero) {
                    width = (char *) malloc(sizeof(char) * (percents->width - percents->precision + 1));
                    ft_memset(width, '0', ft_strlen(width));
                    return (final = ft_strjoin(width, src));
                } else {
                    width = (char *) malloc(sizeof(char) * (percents->width - percents->precision + 1));
                    ft_memset(width, ' ', ft_strlen(width));
                    return (final = ft_strjoin(width, src));
                }
            }
        }
        if (percents->width < nb)
        {
            if (percents->precision > nb)
            {
                precision = (char *)malloc(sizeof(char) * percents->precision - nb + 1);
                ft_memset(precision, '0', ft_strlen(precision));
                return (final = ft_strjoin(precision, src));
            }
        }
        else
	        return (src);
        return (NULL);
}

 /*
            if (percents->precision < nb)
            {
                width = (char *) malloc(sizeof(char) * percents_width - nb + 1);
                ft_memset(width, ' ', ft_strlen(width));
                return (final = ft_strjoinf(width, src));
            }
        }
        if (percents->width > nb && percents->precision > nb)
        {
            if (percents->width > percents->precision)
            {
                width = (char *) malloc(sizeof(char) * (percents->width - percents->precision + 1));
                wp = (char *) malloc(sizeof(char) * percents->width + 1);
                ft_memset(width, ' ', ft_strlen(dst));
                precision = (char *) malloc(sizeof(char) * (percents->precision - nb + 1));
                ft_memset(precision, '0', ft_strlen(precision));
                wp = ft_strjoinf(width, precision);
                return (final = ft_strjoin(wp, src));
            }
            if (percents->width > percents->precision && zero)
            {
                width = (char *) malloc(sizeof(char) * (percents->width + 1));
                ft_memset(width, '0', ft_strlen(dst));
                return (final = ft_strjoin(width, src));
            }
            if (percents->width < percents->precision)
            {
                precision = (char *) malloc(sizeof(char) * percents->precision + 1);
                ft_memset(precision, '0', ft_strlen(precision));
                return (final = ft_strjoinf(precision, src));
            }
        }

}

if (((percents->width) && !(percents->precision)) || ((percents->width) >= (percents->precision)))
{
if (nb > (percents->width))
{
{
str = (char *)malloc(sizeof(char) * percents->width + 1);
ft_strncpy(str, va_arg(arg,
                       char *), (percents->width));
//ft_putstr("0x");
ft_putstr(str);
}
}
}
if ((!((percents->width)) && ((percents->precision))) || ((percents->width) <= (percents->precision)))
{
if (nb > (percents->precision))
{
str = (char *)malloc(sizeof(char) * percents->precision + 1);
ft_strncpy(str, va_arg(arg,
                       char *), (percents->precision));
//ft_putstr("0x");
ft_putstr(str);
}
}
}

*/
