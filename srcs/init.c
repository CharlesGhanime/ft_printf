/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:18:44 by aboitier          #+#    #+#             */
/*   Updated: 2019/09/03 00:31:09 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_reste(t_ptf **word, char *reste)
{
	if (!((*word)->reste = ft_strdup(reste)))
		return (-1);
	return (1);
}

long	total_size(t_ptf *head, int char_size)
{
	long	size;
	t_ptf	*word;

	size = 0;
	word = head->next;
	while (word)
	{
		if (word->symptoms)
			char_size -= ft_strlen(word->symptoms);
		if (!(word->conv == 'w'))
			size += word->size - 2;
		else
			size += word->size - 1;
		word = word->next;
	}
	free_head(head);
	return (size + char_size);
}

t_ptf	*init_head(t_ptf *head)
{
	t_ptf *percents;

	head = NULL;
	if (!(percents = (t_ptf*)malloc(sizeof(t_ptf))))
		return (0);
	percents->options = 0;
	percents->precision = 0;
	percents->pos = 0;
	percents->flags = NULL;
	percents->symptoms = NULL;
	percents->size = 0;
	percents->total_pct_count = 0;
	percents->rank = 0;
	percents->next = NULL;
	percents->width = 0;
	percents->signe = '\0';
	percents->conv = '\0';
	percents->unsignd = 0;
	return (percents);
}

int		init_args(t_ptf *word)
{
	word->conv = '\0';
	word->a_t.a_intmax = 0;
	word->a_t.a_uintmax = 0;
	word->a_t.a_string = NULL;
	word->a_t.a_ptr = NULL;
	word->a_t.a_ldouble = 0;
	return (0);
}

int		init_conv(t_ptf **percents, int rank, char *symptoms)
{
	t_ptf *word;

	word = (*percents)->next;
	while (word->next != NULL)
		word = word->next;
	if (!((word->next) = (t_ptf*)malloc(sizeof(t_ptf))))
		return (0);
	word = word->next;
	word->symptoms = NULL;
	if (symptoms)
		word->symptoms = symptoms;
	word->options = 0;
	word->precision = 0;
	word->pos = 0;
	word->flags = NULL;
	word->size = 0;
	word->total_pct_count = 0;
	word->rank = rank;
	word->width = 0;
	word->signe = '\0';
	word->conv = '\0';
	word->unsignd = 0;
	init_args(word);
	word->next = NULL;
	return (1);
}
