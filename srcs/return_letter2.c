/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_letter2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:38:15 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/23 00:46:35 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_get_octal()
{
	return ('o');
}

char	ft_get_unsigned()
{
	return ('u');
}

char	ft_get_hexa()
{
	return ('x');
}

char	ft_get_hexa_maj()
{
	return ('X');
}

char	ft_get_float()
{
	return ('f');
}

char	ft_get_percent()
{
	return ('%');
}
