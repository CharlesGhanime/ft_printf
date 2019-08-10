/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:36:24 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/24 20:37:59 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcounter(char const *s, char c)
{
	size_t i;
	size_t wordcounter;

	i = 0;
	wordcounter = 0;
	while (s[i])
	{
		if (s[i] != c)
			wordcounter++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (wordcounter);
}
