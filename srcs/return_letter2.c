/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_letter2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:38:15 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/29 02:02:09 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_get_octal(void)
{
	return ('o');
}

char	ft_get_unsigned(void)
{
	return ('u');
}

char	ft_get_hexa(void)
{
	return ('x');
}

char	ft_get_hexa_maj(void)
{
	return ('X');
}

char	ft_get_float(void)
{
	return ('f');
}
