/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:14:30 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/03 12:54:08 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char *s, char c)
{
	char		**str;

	if (!s || !(str = (char**)malloc(sizeof(char*) *
	(ft_wordcounter(s, c) + 1))))
		return (NULL);
	return (ft_filling(s, c, str));
}
