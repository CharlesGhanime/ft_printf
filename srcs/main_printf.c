/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:15:34 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/08 09:36:30 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int a = 42;
	char b = '&';
	char *c = "Belze aime les chats ";
	char *d = " Il en a ";

	printf("printf : %i\n", a);
	ft_printf("ft_printf : %i\n", a);
	printf("printf : %d\n", a);
	ft_printf("ft_printf : %d\n", a);
	printf("printf : %c\n", b);
	ft_printf("ft_printf : %c\n", b);
	printf("printf : %s\n", c);
	ft_printf("ft_printf : %s\n", c);

	printf("printf : %s%c%s%i\n", c, b, d, a);
	ft_printf("ft_printf : %s%c%s%i\n", c, b, d, a);

	return (0);
}
