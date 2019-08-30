/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfrchoz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:16:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/30 11:26:03 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoinfrchoz(char *s1, char *s2, int choice)
{
	char		*new_str;
	size_t		len_s1s2;

	if (!s1 || !s2)
		return (NULL);
	new_str = NULL;
	len_s1s2 = ft_strlen(s1) + ft_strlen(s2);
//	printf("len = %zu\n", len_s1s2);
//	printf("s1 = %s\t s2 = %s\n", s1, s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (len_s1s2 + 1))))
		return (NULL);
//	printf("new0 = %s\n", new_str);
	ft_strcpy(new_str, s1);
//	printf("new1 = %s\n", new_str);
	ft_strcat(new_str, s2);
//	printf("new2 = %s\n", new_str);
	if (choice == 1)
	{
		free(s1);
		s1 = NULL;
	}
	else if (choice == 2)
	{
		free(s2);
		s2 = NULL;
	}
	return ((char *)new_str);
}
