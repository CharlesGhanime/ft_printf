/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:14:31 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/28 23:24:56 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../files/includes/head.h"

int		main(void)
{
	int d181 = 244; 
	unsigned int X182 = 18644;
	float f183 = 15623;

	unsigned int o291 = 28213;
	unsigned int x290 = 8361;

	ft_printf("x 8361 >-4ll<; = %-4llx\n", x290);
	ft_printf("o 28213 >+1.42l > .4L<; = % .4L+1.42lo\n",o291);

	return (0);
}
