/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:43:20 by aboitier          #+#    #+#             */
/*   Updated: 2019/06/17 08:28:30 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    global_info(t_ptf *percents)
{
	FILE *fptr;

	fptr = fopen("logs", "w");
	if (fptr == NULL)
	{
		printf("Error in handling log\n");
		exit(1);
	}
	percents = percents->next;
	fprintf(fptr, "\n");
	while (percents)
	{
		fprintf(fptr, "\t%%"_GREEN"%d"_END"", percents->rank);
		fprintf(fptr, "  conv: "_BBLUE"%c"_END, percents->conv);
		fprintf(fptr, " -pos '%%' dans format: "_YELLOW"%d"_END"  \n", percents->pos);
		fprintf(fptr, "\tsymptoms:"_RED"%s "_END, percents->symptoms);
		fprintf(fptr, "\toptions:"_RED"'%s'\n"_END, percents->options);
		fprintf(fptr, "\twdith:"_RED"'%lu'\n"_END, percents->width);
		fprintf(fptr, "\tprecision:"_RED"'%lu'\n"_END, percents->precision);
		fprintf(fptr, "\tflags:"_RED"'%s'"_END, percents->flags);
//		if (((percents->key / 10000) < 2))
//			fprintf(fptr, "\ttype:"_GREEN"'unsigned %s'\n"_END, percents->type);
//		else
			fprintf(fptr, "\ttype:"_GREEN"'%s'\n"_END, percents->type);
		fprintf(fptr, "\tsize:"_GREEN"'%lu'\n"_END, percents->size);
//		fprintf(fptr, "\tkeyc:"_BGREEN"'%s'\n\n"_END, percents->keyc);
//		fprintf(fptr, "\tvar: = %s", percents->a_t.a_char);
		fprintf(fptr, "\n");
		percents = percents->next;
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
