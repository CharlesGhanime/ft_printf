/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 07:10:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/02/17 07:11:26 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_info(t_ptf *percents)
{
	percents = percents->next;
	while (percents)
	{
		printf("\t%%"_GREEN"%d"_END" "_BBLUE"%c"_END" conv symptoms "_RED"%s"_END"\n", percents->rank, percents->conv, percents->symptoms);
		percents = percents->next;
	}
}
