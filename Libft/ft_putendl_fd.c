/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:02:11 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/19 15:19:07 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i] && s)
			ft_putchar_fd(s[i++], fd);
		ft_putchar_fd('\n', fd);
	}
}
