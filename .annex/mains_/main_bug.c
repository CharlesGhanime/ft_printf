/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:14:31 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/03 03:11:37 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../includes/head.h"

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
ft_printf(""_BBLUE"d"_END" "_MAGENTA"1026"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"5292"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"14244"_END" >"_CYAN" 9.11ll"_END"<; = % 9.11lld\n"_BBLUE"d"_END" "_MAGENTA"1094"_END" >"_CYAN" 4.11ll"_END"<; = % 4.11lld\n", d10,d11,d12,d13);
	int d13 = 1094;
	int d12 = 14244;
	int d11 = 5292;
	int d10 = 1026;
