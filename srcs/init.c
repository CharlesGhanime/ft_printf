/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:18:44 by aboitier          #+#    #+#             */
/*   Updated: 2019/06/14 14:08:29 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long		total_size(t_ptf *head, int char_size)
{
	long	size;
	t_ptf	*word;

	size = 0;
	word = (head)->next;
	while (word->next)
	{
		if (word->symptoms)
			char_size -= ft_strlen(word->symptoms) + 1;
		size += word->size;
		word = word->next;
	}
	return (size + char_size);
}

t_ptf		*init_head(t_ptf *head)
{
	head = NULL;
	t_ptf *percents;
	
	if (!(percents = (t_ptf*)malloc(sizeof(t_ptf))))
		return (0);
	percents->options = NULL;
	percents->precision = 0;
	percents->flags = NULL;
	percents->symptoms = NULL;
	percents->total_pct_count = 0;
	percents->rank = 0;
	percents->next = NULL;
	return (percents);
}

int		init_args(t_ptf *word)
{
	word->a_t.a_short = 0;
	word->a_t.a_int = 0;
	word->a_t.a_long = 0;
	word->a_t.a_llong = 0;
	word->a_t.a_unchar = 0;
	word->a_t.a_unint = 0;
	word->a_t.a_unshort = 0;
	word->a_t.a_unlong = 0;
	word->a_t.a_unllong = 0;
	word->a_t.a_char = 0;
	word->a_t.a_string = NULL;
	word->a_t.a_ptr = 0;
	word->a_t.a_float = 0;
	word->a_t.a_double = 0;
	word->a_t.a_ldouble = 0;
	return (0);
}

int		init_conv(t_ptf **percents, int rank, char *symptoms, char conv)
{
	t_ptf *word;

	word = (*percents)->next;
	while (word->next != NULL)
		word = word->next;
	if (!((word->next) = (t_ptf*)malloc(sizeof(t_ptf))))
		return (0);
	word = word->next;
	word->conv = conv;
	word->symptoms = NULL;
	if (symptoms)
	{
		word->symptoms = (char*)ft_memalloc(ft_strlen(symptoms) + 1);
		word->symptoms = ft_strcpy(word->symptoms, symptoms);
	}
	word->type = NULL;
	word->options = NULL;
	word->precision = 0;
	word->width = 0;
	word->rank = rank;
	init_args(word);
	word->next = NULL;
	return (1);
}
