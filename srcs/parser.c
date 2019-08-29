/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:38:04 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/29 07:03:41 by aboitier         ###   ########.fr       */
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
	{
		if (format[i] == '%')
		{
			if ((position = ft_auscultate(format + i + 1)) != -1)
			{
				doctor((char*)format + i + 1, ++pct_count, position, head);
				add_pct_pos(head, i, 1, format[position + i + 1]);
				i += position + 1;
			}
			else 
				set_invalid(format + i + 1, ++pct_count, head);
		}
	}
	if (!pct_count)
		return (0);
	(*head)->total_pct_count = pct_count;
	return (1);
}

int		ft_auscultate(char *patient)
{
	int		i;
	int		j;
	char	needle[12];

	ft_memcpy(needle, "diouxXfcsp%", 11);
	i = -1;
	while (patient[i++])
	{
		j = -1;
		while (patient[i] != needle[j++] && patient[i] && needle[j])
		{
			if (patient[i] == needle[j])
				return (i);
		}
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

	symptoms = NULL;
	symptoms = ft_strsub(format, 0, position);
	if ((*percents)->next == NULL)
	{
		if (!((*percents)->next = (t_ptf*)malloc(sizeof(t_ptf))))
			return (0);
		(*percents)->next->rank = rank;
		(*percents)->next->symptoms = NULL;
		(*percents)->next->symptoms = symptoms;
		(*percents)->next->options = 0;
		(*percents)->next->width = 0;
		(*percents)->next->precision = 0;
		(*percents)->next->flags = NULL;
		(*percents)->next->next = NULL;
		return (1);
	}
	else
		init_conv(percents, rank, symptoms);
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
