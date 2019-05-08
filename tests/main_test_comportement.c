/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_comportement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:42:17 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/08 16:53:48 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <math.h>
#include <stdarg.h>

int main ()
{
	int nul = 42;
	unsigned long i;
	unsigned long *p = NULL;
//	unsigned long *n = NULL;
	long int l = 42;
	long long int ll = 42;
	float f = 42.4242;
	char *s = "J'aime les chocolats";
	char cha = 'c';
	printf("***********************Gestion des Floats**********************\n");
//	printf("%i\n", i);
//	printf("%.5i\n", i);
	printf("%.4f\n", f);
	printf("%#.4f\n", f);
//	printf("%16.14li\n", l);
//	printf("%16.14lld\n", ll);
	printf("%-6c", cha);

	printf("%s\n", s);
	printf("%-s\n", s);
//	printf("%12.14d\n", i);
//	printf("%+s\n", s);

	printf("x = %#x", nul);
	printf("***********************Gestion des adresses********************\n");

//	printf("0x");
	printf("0x%lx\n%p\n", i, p);
//	printf("%lx\n%p\n", *n, n);
	printf("***********************Tests decalage binaire******************\n");
	char a = 0;
	int b = 0;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	a = 1 << 0;
	b = (b | 1 << 0);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	a = 1 << 1;
	b = (b | 1 << 1);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	a = 1 << 2;
	b = (b | 1 << 2);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	a = 1 << 6;
	b = (b | 1 << 6);
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	b = 0;
	int c;
	b = 1 << 7;
	printf("valeur set de b (b = 1 << 7) : %d\n", b);
	if ((c = (((b == 1 << 7)))))
		printf("CONDITION IS TRUE\n");
	printf("c = %d\n", c);
	printf("b << 0 = %d\n", b << 0);
	printf("b << 1 = %d\n", b << 1);
	printf("b << 2 = %d\n", b << 2);
	printf("b << 3 = %d\n", b << 3);
	printf("b << 4 = %d\n", b << 4);
	printf("b << 5 = %d\n", b << 5);
	printf("b << 6 = %d\n", b << 6);
	printf("b << 7 = %d\n", b << 7);
	printf ("%d\n", b << 5);
	if (b << 1)
		printf("Working");

//	write(1, "0", 50);

	return (0);
}
