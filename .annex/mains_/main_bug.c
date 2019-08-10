/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:14:31 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/10 18:00:38 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../includes/head.h"

int		main(void)
{
	float 	f1 = 0.1, f2 = 0.2, f3 = 0.3, f4 = 0.4, f5 = 0.5, f6 = 0.6, f7 = 0.7, f8 = 0.8, f9 = 0.9;
	int		i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 5, i6 = 6;
	printf("%d, %d, %d, %d, %d, %d\n%f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n", 
		f1, f2, f3, f4, f5, f6, f7, f8, f9, i1, i2, i3, i4, i5, i6);

	unsigned int o291 = 28213;
	unsigned int x290 = 8361;
	int d181 = 244; 
	unsigned int X182 = 18644;
	float f183 = 15623;
	ft_printf("x 8361 >-4ll<; = %-4llx\n", x290);
	ft_printf("o 28213 >+1.42l > .4L<; = % .4L+1.42lo\n",o291);

	int d13 = 1094;
	int d12 = 14244;
	int d11 = 5292;
	int d10 = 1026;

ft_printf(""_BBLUE"d"_END" "_MAGENTA"1026"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"5292"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"14244"_END" >"_CYAN" 9.11ll"_END"<; = % 9.11lld\n"_BBLUE"d"_END" "_MAGENTA"1094"_END" >"_CYAN" 4.11ll"_END"<; = % 4.11lld\n", d10,d11,d12,d13);
	return (0);
}

