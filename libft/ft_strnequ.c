/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:48:03 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/03 12:53:11 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


int		ft_strnequ(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (s1 == s2 ? 1 : 0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 4)
		printf("%i", ft_strnequ(argv[1], argv[2], ft_atoi(argv[3])));

	return (0);
}
