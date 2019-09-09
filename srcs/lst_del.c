/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:48:37 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/29 05:07:30 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	lst_del(t_ptf *percents)
{
	if (percents && percents->next)
		lst_del(percents->next);
	free(percents);
}

void	percent_node_free(t_ptf *percents)
{
	t_ptf *head;
	t_ptf *tmp;

	head = NULL;
	head = percents;
	while (percents)
	{
		tmp = percents;
		percents = percents->next;
		free(tmp);
	}
	head = NULL;
}
