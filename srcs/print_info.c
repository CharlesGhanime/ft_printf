/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:43:20 by aboitier          #+#    #+#             */
/*   Updated: 2019/05/06 11:44:10 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	word_info(t_ptf *word)
{
	printf("rank = %d conv = %c\n", word->rank, word->conv);
	printf("symptoms =%s\n", word->symptoms);
	printf("options = %s\n", word->options);
	printf("width = %lu\n", word->width);
	printf("precision = %lu\n", word->precision);
	printf("flags = %s\n", word->flags);
	printf("type = %s\n", word->type);
	printf("\n");
}

void    global_info(t_ptf *percents)
{
	percents = percents->next;
	printf("\n");
	while (percents)
	{
		printf("\t%%"_GREEN"%d"_END"", percents->rank);
		printf("  conv: "_BBLUE"%c"_END, percents->conv);
		printf(" -pos '%%' dans format: "_YELLOW"%d"_END"  \n", percen
				ts->pos);
		printf("\tsymptoms:"_RED"%s "_END, percents->symptoms);
		printf("\toptions:"_RED"'%s'\n"_END, percents->options);
		printf("\twdith:"_RED"'%lu'\n"_END, percents->width);
		printf("\tprecision:"_RED"'%lu'\n"_END, percents->precision);
		printf("\tflags:"_RED"'%s'"_END, percents->flags);
		if (((percents->key / 10000) < 2))
			printf("\ttype:"_GREEN"'unsigned %s'\n"_END, percents->type);
		else
			printf("\ttype:"_GREEN"'%s'\n"_END, percents->type);
		printf("\tkey:"_GREEN"'%d'\n"_END, percents->key);
		printf("\tkeyc:"_BGREEN"'%s'\n\n"_END, percents->keyc);

		percents = percents->next;
	}
}

