/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:31:19 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/29 21:10:12 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		free_head(t_ptf *head)
{
	t_ptf *tmp;
	t_ptf *word;
	
	if (!head->conv)
		return (0);
	tmp = NULL;
	word = head->next;
	while (word)
	{
		tmp = word;
		if (word->flags)
			free(word->flags);
		if (word->symptoms)
			free(word->symptoms);
		if (word->conv == 'w' && word->reste)
			free(word->reste);
		word = word->next;
		free(tmp);
	}
	free(head);
	return (0);
}
