/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 08:18:32 by cghanime          #+#    #+#             */
/*   Updated: 2019/03/25 08:20:46 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <stdio.h>

void putCh(char c) 
{
	write(1, &c, 1); 
}

	void putStr(const char *str) 
{ 
	size_t i = 0; 
	
	while (str[i]) putCh(str[i++]); 
} 

void putInteger(int nb) 
{ 
	if (nb < 0) 
	{ 
		putCh('-'); 
		nb = nb * (-1); 
	} 
	
	if (nb >= 10) 
	{ 
		printf("debut - %d", nb); 
		putInteger(nb / 10); 
		printf("milieu - %d", nb); 
		putInteger(nb % 10); 
		printf("fin - %d", nb); 
	} 
	else putCh('0' + nb); 
}
