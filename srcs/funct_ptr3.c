/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ptr3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:43:37 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 23:11:16 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_pfunc		ft_get_print_percent(void)
{
	return (ft_print_percent);
}

t_pfunc		ft_get_print_invalid(void)
{
	return (ft_print_invalid);
}
