/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:00:06 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/20 11:41:57 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

boolean			is_token(char token, char c)
{
	if (c == token)
		return (TRUE);
	return (FALSE);
}

boolean			is_format(size_t bool_format)
{
	if (bool_format != TRUE)
		return (TRUE);
	return (FALSE);
}

void			ft_lst_format_token_init(t_format lst_format[NB_FORMAT])
{
	lst_format[CHAR].token = ft_get_char();
	lst_format[STRING].token = ft_get_string();
	lst_format[ADDRESS].token = ft_get_address();
	lst_format[DECIMAL].token = ft_get_decimal();
	lst_format[INTEGER].token = ft_get_integer();
	lst_format[OCTAL].token = ft_get_octal();
	lst_format[UNSIGNED].token = ft_get_unsigned();
	lst_format[HEXA].token = ft_get_hexa();
	lst_format[HEXA_MAJ].token = ft_get_hexa_maj();
	lst_format[FLOAT].token = ft_get_float();

	lst_format[CHAR].next_format = STRING;
	lst_format[STRING].next_format = ADDRESS;
	lst_format[ADDRESS].next_format = DECIMAL;
	lst_format[DECIMAL].next_format = INTEGER;
	lst_format[INTEGER].next_format = OCTAL;
	lst_format[OCTAL].next_format = UNSIGNED;
	lst_format[UNSIGNED].next_format = HEXA;
	lst_format[HEXA].next_format = HEXA_MAJ;
	lst_format[HEXA_MAJ].next_format = FLOAT;
	lst_format[FLOAT].next_format = NO_FORMAT;

	lst_format[CHAR].func = ft_get_print_char();
	lst_format[STRING].func = ft_get_print_string();
	lst_format[ADDRESS].func = ft_get_print_address();
	lst_format[DECIMAL].func = ft_get_print_decimal();
	lst_format[INTEGER].func = ft_get_print_integer();
	lst_format[OCTAL].func = ft_get_print_octal();
	lst_format[UNSIGNED].func = ft_get_print_unsigned();
	lst_format[HEXA].func = ft_get_print_hexa();
	lst_format[HEXA_MAJ].func = ft_get_print_hexa_maj();
	lst_format[FLOAT].func = ft_get_print_float();
}

void			ft_format_cmp(char c, t_ptf *percents)
{
	size_t			check_format = FALSE;
	t_format		lst_format[NB_FORMAT];
	FORMAT_TOKEN	current_format = CHAR;

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
	if (!(word->conv) && word->total_pct_count > 1)
		write(1, "%", 1);
	else
		write(1, format + start, len);
	return (0);
}	

int		lobby(const char *format, t_ptf *percents)
{
	t_ptf *word;
	int start;

	start = 0;
	word = percents->next;
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
		write(1, format + start, (int)ft_strlen((char*)format) - start);
	return (1);
}


int			ft_printf(const char *format, ...)
{
	va_list		arg;
	t_ptf		*percents = NULL;
	int i;

	percents = init_head(percents);
	if(!(ft_count_pct((char *)format, &percents)))
		{
		ft_putstr((char *)format);
		return(ft_strlen((char *)format));
		}
	va_start(arg, format);
	blood_test(&percents, arg);

//	printf("==%d \n\n", percents->next->a_t.a_int);
//	printf("%s \n\n", percents->next->a_t.a_string);
//	printf("%s\n\n", percents->next->a_t.a_string);
//	printf("%s\n\n", percents->next->a_t.a_string);
	i = 0;

	lobby(format, percents);
	
//	printf("\ntotal size = %ld\n", total_size(percents, ft_strlen((char *)format))); 

	global_info(percents);
	va_end(arg);
		return (total_size(percents, ft_strlen((char *)format)));
}


