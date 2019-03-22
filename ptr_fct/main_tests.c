/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:40:52 by cghanime          #+#    #+#             */
/*   Updated: 2019/03/20 19:13:31 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MAX = 2147483647 INT_MIN = -2147483648

#include <libc.h>
#include <stdarg.h>

int		addition(int a, int b)
{
	if (a < INT_MIN || b < INT_MIN || a > INT_MAX || b > INT_MAX)
		return (0);
	return (a + b);
}

int		soustraction(int a, int b)
{
	if (a < INT_MIN || b < INT_MIN || a > INT_MAX || b > INT_MAX)
		return (0);
	return (a - b);
}

int		main(void)
{
	int	(*ptr_fct)(int, int) = &addition;
	int ret;

	ret = ptr_fct(50,50);
	printf("ret = %d", ret);
	return (0);
}
