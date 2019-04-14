/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_comportement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:42:17 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/14 12:40:35 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <math.h>
#include <stdarg.h>

int main ()
{
	int f = 42;
	printf("***********************Gestion des Floats**********************\n");
	printf("%-6.4d\n", f);
	printf("***********************Tests decalage binaire******************\n");
	int b = 0;
	printf("%d\n", b << 7);
	b = 1 << 7;
	printf("%d\n", b);
	if ((b == 1 << 5) & 1)
		printf("CONDITION IS TRUE\n");
	printf("%d\n", b << 0);
	printf("%d\n", b << 1);
	printf("%d\n", b << 2);
	printf("%d\n", b << 3);
	printf("%d\n", b << 4);
	printf("%d\n", b << 5);
	printf("%d\n", b << 6);
	printf("%d\n", b << 7);
//	printf ("%d\n", b << 5);
	if (b << 1)
		printf("Working");

	return (0);
}
