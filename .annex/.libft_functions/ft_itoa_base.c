/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:34:02 by cghanime          #+#    #+#             */
/*   Updated: 2019/05/06 11:00:51 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	int octal[9] = {0, 1 ,2, 3, 4, 5, 6, 7, 10};
	int len;
	unsigned int r;

	hexa = "0123456789abcdef";
	len = ft_counter_base(nb, base);
	r = 0;
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	tab[len] = '\0';
	if (base == 2)
	{
		while (len >= 0)
		{
			r = nb % base;
			tab[len] = r + '0';
			if (r < 2)
				tab[len--] = octal[r] + '0';
			nb = nb / base;
		}
	}
	if (base == 8)
	{
		while (len >= 0)
		{
			r = nb % base;
			tab[len] = r + '0';
			if (r < 8)
				tab[len--] = octal[r] + '0';
			nb = nb / base;
		}
	}
	if (base == 16)
	{
		while (len >= 0)
		{
			r = nb % base;
			tab[len] = r + '0';
			if (r < 16)
				tab[len--] = hexa[r];
			nb = nb / base;
		}
	}
	else
	{
		while (len >= 0)
		{
			r = nb % base;
				tab[len] = r + '0';
				if (r < base)
					tab[--len] = nb % base + '0';
				nb = nb / base;
		}
	}
	return (tab);
}
