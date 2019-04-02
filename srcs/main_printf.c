/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:15:34 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/02 15:46:42 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int d = 55;
	char c = 'a';
	char *s = "Je me presente : ";
	ft_printf("%d\n", 55);
	ft_printf("%c\n", c);
	ft_printf("Coucou! %s Je suis ton ft_printf\n", s);
	return (0);
}
