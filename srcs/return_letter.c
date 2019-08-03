/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:47:36 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/14 16:36:39 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_get_char()
{
	return ('c');
}

char	ft_get_string()
{
	return ('s');
}

char	ft_get_address()
{
	return ('p');
}

char	ft_get_decimal()
{
	return ('d');
}

char	ft_get_integer()
{
	return ('i');
}
