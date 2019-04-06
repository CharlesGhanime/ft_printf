/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:55:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/04/01 11:54:00 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int main(void)
{
	int i;
	void *str;
//	unsigned char **addr;

	i = 0;
//	addr = &str;
	printf("str's address : %p\n", &addr);
	printf("addr's address : %p\n", addr);
	while (str[i++])
	{
		printf("str's address : %02x\n", str[i]);
//		printf("str's address : %02x\n", str[i]);
	}
	return (0);
}
