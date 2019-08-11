/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfrchoz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:16:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/08 04:55:46 by aboitier         ###   ########.fr       */
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
	len_s1s2 = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (len_s1s2 + 1))))
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strcat(new_str, s2);
	if (choice == 1)
		free(s1);
	else if (choice == 2)
		free(s2);
	return ((char *)new_str);
}
