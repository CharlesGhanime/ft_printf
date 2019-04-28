/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_comportement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:42:17 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/28 14:29:02 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <math.h>
#include <stdarg.h>

int main ()
{
	int i = 42;
	long int l = 42;
	long long int ll = 42;
	float f = 42.4242;
	char *s = "J'aime les chocolats";
	printf("***********************Gestion des Floats**********************\n");
	printf("%i\n", i);
	printf("%.5i\n", i);
	printf("%.4f\n", f);
	printf("%#.4f\n", f);
//	printf("%16.14li\n", l);
//	printf("%16.14lld\n", ll);

//	printf("%12.14d\n", i);
//	printf("%16.14s", s);

	printf("***********************Tests decalage binaire******************\n");
//	int b = 0;
//	printf("%d\n", b << 7);
//	b = 1 << 7;
//	printf("valeur set de b (b = 1 << 7) : %d\n", b);
//	if ((b == 1 << 5) & 1)
//		printf("CONDITION IS TRUE\n");
//	printf("b << 0 = %d\n", b << 0);
//	printf("b << 1 = %d\n", b << 1);
//	printf("b << 2 = %d\n", b << 2);
//	printf("b << 3 = %d\n", b << 3);
//	printf("b << 4 = %d\n", b << 4);
//	printf("b << 5 = %d\n", b << 5);
//	printf("b << 6 = %d\n", b << 6);
//	printf("b << 7 = %d\n", b << 7);
//	printf ("%d\n", b << 5);
//	if (b << 1)
//		printf("Working");

//	write(1, "0", 50);

	return (0);
}
