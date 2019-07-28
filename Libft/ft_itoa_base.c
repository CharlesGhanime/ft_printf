/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:34:02 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/25 18:18:39 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counter_base(unsigned int nb, unsigned int base)
{
	int counter;

	counter = 0;
	if (nb == 0)
		return (counter = 1);
	while (nb != 0)
	{
		nb = nb / base;
		counter++;
	}
	counter -= 1;
	return (counter);
}

char	*ft_itoa_base(unsigned int nb, unsigned int base)
{
	char *tab;
	char *hexa;
	int len;
	unsigned int r;

	hexa = "0123456789abcdef";
	len = ft_counter_base(nb, base);
	r = 0;
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	tab[len] = '\0';
	if (base == 0)
		return(NULL);
	while (len >= 0)
	{
		r = nb % base;
		tab[len] = r + '0';
		if (r < base)
			tab[len] = hexa[r] + '0';
		nb = nb / base;
		len--;
	}
	return (tab);
}

int main(int argc, char **argv)
{
	int i = 1;

	if (argc > 1)
		printf("%s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	else
		write(1, "usage : char *ft_itoa_base(unsigned int nb, unsigned int base)\n", 63);
	return (0);
}
