/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:47:36 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/29 02:02:03 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_get_char(void)
{
	return ('c');
}

char	ft_get_string(void)
{
	return ('s');
}

char	ft_get_address(void)
{
	return ('p');
}

char	ft_get_decimal(void)
{
	return ('d');
}

char	ft_get_integer(void)
{
	return ('i');
}
