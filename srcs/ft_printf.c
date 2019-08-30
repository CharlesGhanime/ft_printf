/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:00:06 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/30 16:37:21 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_lst_format_token_init(t_format lst_format[NB_FORMAT])
{
	ft_lst_token_init(lst_format);
	ft_lst_format_init(lst_format);
	ft_lst_pfunc_init(lst_format);
}

void			ft_format_cmp(char c, t_ptf *percents)
{
	size_t			check_format = FALSE;
	t_format		lst_format[NB_FORMAT];
	t_format_token	current_format = CHAR;

	ft_lst_format_token_init(lst_format);
	while (current_format != NO_FORMAT)
	{
		if (lst_format[current_format].token == c)
		{
			/*if (*/lst_format[current_format].func(percents)/* == FALSE)*/;
				//insert free
			check_format = TRUE;
			break ;
		}
		current_format = lst_format[current_format].next_format;
	}
}

int		print_format(const char *format, t_ptf *word, int start)
{
	int len;

	len = word->pos - start;
//	if (!(word->conv) && word->total_pct_count > 1)
//		write(1, "%", 1);
//	else
	write(1, format + start, len);
	return (0);
}	

int		lobby(const char *format, t_ptf *percents)
{
	t_ptf *word;
	int start;

	start = 0;
	word = percents->next;
	if (word->valid == 1)
		(word->pos == 0) ? (start = (int)ft_strlen(word->symptoms) + 2)
		: (start = 0);
	while (word)
	{
		print_format(format, word, start);
		ft_format_cmp(word->conv, word);
		start = word->pos + ft_strlen(word->symptoms) + 2;
		word = word->next;
	}
	if (format[start])
	{	
//		printf("start = %d\n", start);
		write(1, format + start, (int)ft_strlen((char*)format) - start);
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		arg;
	t_ptf		*percents;

	percents = NULL;
	percents = init_head(percents);
	if (!(ft_count_pct((char *)format, &percents)))
	{
		ft_putstr((char *)format);
		return(ft_strlen((char *)format));
	}
	va_start(arg, format);
	blood_test(&percents, arg);
	lobby(format, percents);
//	global_info(percents);
	va_end(arg);
	return (total_size(percents, ft_strlen((char *)format)));
}
