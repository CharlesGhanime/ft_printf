/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:08:49 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/04 16:43:02 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*J'ai besoin de recuperer la liste chainee en argument*/

/* je vais utiliser le char *option
 * que je dois parcourir pour savoir
 * si j'ai l'option "-", "+" etc*/

void	ft_minus_flag(va_list arg, int flags, int fw, int pr)
{
	int i;
	while (option[i])
		if (option[i] == '-')
			if ()
}

void	ft_flag_plus(va_list arg)
{
	if (va_arg(arg, int) >= 0 || va_arg(arg, double) >= 0)
		ft_putchar('+');
}
