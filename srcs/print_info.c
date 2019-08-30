/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:43:20 by aboitier          #+#    #+#             */
/*   Updated: 2019/08/30 01:55:32 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    global_info(t_ptf *percents)
{
	FILE *fptr;
	t_ptf *word;

	fptr = fopen("logs", "a");
	fprintf(fptr, "Here are your variables. Be careful. Love you.\n");
	if (fptr == NULL)
	{
		printf("Error in handling log\n");
		exit(1);
	}
	word = percents->next;
	fprintf(fptr, "\n");
	while (word)
	{
		fprintf(fptr, "\t%%"_GREEN"%d"_END"", word->rank);
		fprintf(fptr, "  conv: "_BBLUE"%c"_END, word->conv);
		fprintf(fptr, " -pos '%%' dans format: "_YELLOW"%d"_END"  \n", word->pos);
		fprintf(fptr, "\tsymptoms:"_RED"|%s|"_END, word->symptoms);
//		fprintf(fptr, "\toptions:"_RED"'%s'\n"_END, word->options);
		if (word->options & PLUS)
			fprintf(fptr, " "_RED"PLUS"_END);
		if (word->options & SPACE) 
			fprintf(fptr, " "_RED"SPACE"_END);
		if (word->options & HASH)
			fprintf(fptr, " "_RED"HASH"_END);
		if (word->options & ZERO)
			fprintf(fptr, " "_RED"ZERO"_END);
		if (word->options & MINUS)
			fprintf(fptr, " "_RED"MINUS"_END);

		fprintf(fptr, "\n\twidth:"_RED"'%lu'\t"_END, word->width);
		fprintf(fptr, "\tprecision:"_RED"'%ld'\n"_END, word->precision);
		fprintf(fptr, "\tflags:"_RED"'%s'"_END, word->flags);
//		if (((word->key / 10000) < 2))
//			fprintf(fptr, "\ttype:"_GREEN"'unsigned %s'\n"_END, word->type);
//		else
		fprintf(fptr, "\tsize:"_GREEN"'%lu'\n"_END, word->size);
		fprintf(fptr, "\tvalid:"_BGREEN"'%d'\n\n"_END, word->valid);
		fprintf(fptr, "\treste:"_BBLUE"'%s'\n\n"_END, word->reste);
		
//		fprintf(fptr, "\tvar: = %s", word->a_t.a_char);
		fprintf(fptr, "\n");
		word = word->next;
	}
	fclose(fptr);
}
/*
void	word_info(t_ptf *word)
{
	fprintf(fptr, "rank = %d conv = %c\n", word->rank, word->conv);
	fprintf(fptr, "symptoms =%s\n", word->symptoms);
	fprintf(fptr, "options = %s\n", word->options);
	fprintf(fptr, "width = %lu\n", word->width);
	fprintf(fptr, "precision = %lu\n", word->precision);
	fprintf(fptr, "flags = %s\n", word->flags);
	fprintf(fptr, "type = %s\n", word->type);
	fprintf(fptr, "\n");
}


*/
