/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 20:31:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/19 20:45:13 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_const_char(const char *str)
{
//	str = (char *)malloc(sizeof(char) * 6 + 1);
	str = "coucou\n";
	return ((char *)str);
}

int main(void)
{
	char *str;

printf("return of ft_const_char : %s\n", ft_const_char(str));
str = strcpy(str, "kkkkkk\n");
printf("value of str : %s\n", str);
str = "aaaaaa\n";
printf("value of str : %s\n", str);
return (0);
}
