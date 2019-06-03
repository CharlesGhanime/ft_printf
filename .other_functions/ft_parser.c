/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:52:50 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/15 13:45:59 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_parser_format(char *format)
{
	int i;
	int j;
	char *flags;
	
	i = 0;
	j = 0;
	flags = (char *)malloc(sizeof(char) * ft_strlen(format) + 1);
	ft_bzero(flags, ft_strlen(format) + 1);
	while (format[i])
	{
		if (format[i] == '%')
			while (format[i] != 'c' && format[i] != 's' && format[i] != 'p'
			&& format[i] != 'd' && format[i] != 'i' && format[i] != 'o'
			&& format[i] != 'u' && format[i] != 'x' && format[i] != 'X'
			&& format[i] != 'f')
			{
				flags[j] = format[i];
				i++;
				j++;
			}
	flags[j] = format[i];
			i++;
	}
	printf("flags = %s\n", flags);
	return (flags);
}
 /*
void	*ft_flags_management(char *flags)
{
	int i;
	int j;
	int fw;
	int pr;
	char *s1;
	char *s2;

	i = 0;
	j = 0;
	s1 = (char *)malloc(sizeof(char) * ft_strlen(flags) + 1);
	while (flags[i])
	{
		if (flags[i] == 'd')
		{
			i = 0;
			while (flags[i])
			{
				if (flags[i] == '-')
				{
				}
				if (flags[i] == '+')
				{
				}
				if (flags[i] == '#')
				{
				}
				if (flags[i] == '0')
				{
				}
				if (flags[i] == ' ')
				{
				}
				if (flags[i] >= '1' && flags[i] <= '9' && flags[i - 1] != '.')
				{
					while (flags[i] >= '1' && flags[i] <= '9')
					{
						
					}
				}
				if (flags[i] >= '1' && flags[i] <= '9' && flags[i - 1] == '.')
				{
				}
			i++;
			}
		}
		i++;
	}
}
*/

int main(void)
{
	ft_parser_format("icoucou%-+#0 12.4hhd%-+4.6llf");
	return (0);
}
