/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cprintf_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 08:16:16 by cghanime          #+#    #+#             */
/*   Updated: 2019/03/27 12:25:15 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cprintf.h"

int affStr(va_list av)
{
	putStr(va_arg(av, char *));
	return true;
}

	int affCh(va_list av)
{
	char c;
	c = va_arg(av, int);
	putCh(c);
	return true;
}

int affInt(va_list av)
{
	putInteger(va_arg(av, int));
	return true;
}
