/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:39:38 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/06 12:39:40 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>


int main (void)
{
    t_ptf *percents;
    size_t nb;
    char *fl = "15.5";
    char *src = "15";
    int i = 15;
    char c = 'c';

    percents->options = "#";
    percents->width = 1;
    percents->precision = 5;
    percents->conv = 'X';
    nb = 2;

//    ft_minus_flag(percents, nb);
//    ft_plus_flag(arg, percents);
//    ft_hashtag_flag(percents);
//    ft_zero_flag(percents, nb);
//    ft_float_precision_flag(fl);

//    printf ("retour ft_minus_flag      :%s\n", ft_minus_flag (percents, nb));
//    printf ("retour ft_plus_flag       :%s\n", ft_plus_flag (arg, percents, nb));
    ft_hashtag_flag(percents);
//    printf ("retour ft_zero_flags      :%s\n", ft_zero_flags(src, percents, nb));
//   printf ("retour ft_float_precision :%s\n", ft_float_precision(src, percents, nb));
//    printf ("retour ft_width_precision :%s\n", ft_width_precision(src, percents, nb));
    printf ("\nretour de printf          :%1.5d\n", i);
    return (0);
}
