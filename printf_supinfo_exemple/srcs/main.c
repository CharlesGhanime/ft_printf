/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 08:20:56 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/07 11:15:26 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cprintf.h" 

int main(void)
{
	char c = 'a';
	char *s = "Hello World!";
	int d = 500;
	cprintf("%d", d);
	cprintf("%s", s);
	cprintf("%c", c);
}
