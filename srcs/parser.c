/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:38:04 by aboitier          #+#    #+#             */
/*   Updated: 2019/09/03 00:31:49 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_count_pct(char *format, t_ptf **head)
{
	int i;
	int pct_count;
	int	position;

	i = -1;
	position = 0;
	pct_count = 0;
	while (format && format[++i])
		if (format[i] == '%')
		{
			if ((position = ft_auscultate(format + i + 1)) != -1)
			{
				doctor(ft_strdup((char*)format + i + 1), ++pct_count,
				position, head);
				add_pct_pos(head, i, 1, format[position + i + 1]);
				i += position + 1;
			}
			else
				set_invalid(ft_strdup(format + i + 1), ++pct_count, head);
		}
	if (!pct_count)
		return (0);
	(*head)->total_pct_count = pct_count;
	return (1);
}

int		ft_auscultate(char *patient)
{
	int					i;

	i = 0;
	while (patient[i] != '\0')
	{
		if (ft_strchr("diouxXfcsp%", patient[i]) != NULL)
			return (i);
		i++;
	}
	return (-1);
}

int		set_invalid(char *format, int pct_count, t_ptf **head)
{
	int pos;

	pos = ft_strlen(format);
	doctor(format, pct_count, pos, head);
	add_pct_pos(head, pos, -1, 'w');
	return (1);
}

int		doctor(char *format, int rank, int position, t_ptf **percents)
{
	char	*symptoms;

	symptoms = ft_strsub(format, 0, position);
	if ((*percents)->next == NULL)
	{
		if (!((*percents)->next = (t_ptf*)malloc(sizeof(t_ptf))))
			return (0);
		(*percents)->next->options = 0;
		(*percents)->next->precision = 0;
		(*percents)->next->pos = 0;
		(*percents)->next->flags = NULL;
		(*percents)->next->symptoms = symptoms;
		(*percents)->next->size = 0;
		(*percents)->next->total_pct_count = 0;
		(*percents)->next->rank = rank;
		(*percents)->next->width = 0;
		(*percents)->next->next = NULL;
		(*percents)->next->signe = '\0';
		(*percents)->next->unsignd = 0;
		init_args((*percents)->next);
	}
	else
		init_conv(percents, rank, symptoms);
	free(format);
	return (1);
}

int		add_pct_pos(t_ptf **percents, int pos, int valid, char conv)
{
	t_ptf *word;

	word = (*percents)->next;
	while (word->next != NULL)
		word = word->next;
	word->pos = pos;
	word->valid = valid;
	word->conv = conv;
	word->reste = NULL;
	return (1);
}
