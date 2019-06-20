/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff_reforged.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:35:39 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/21 01:12:14 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* PRINT CHAR */

int		ft_print_char(t_ptf *percents)
{
	percents->size = 1;
	ft_putchar((char)percents->a_t.a_int);
	return (TRUE);
}

/* PRINT STRING */

char	*str_width(char *str, long width, int token)
{
	char *spaces;
	long i;

	i = -1;
	if (!(spaces = (char *)malloc(sizeof(char) * (width + 1))))
		return (NULL);
	while (++i < width - (long)ft_strlen(str))
		spaces[i] = ' ';
	spaces[i] = '\0';
	if (token == 0)
	{
		if (!(spaces = ft_strjoin(spaces, str)))
			return (NULL);
	}
	else if (token == 1)
		if (!(spaces = ft_strjoin(str, spaces)))
			return (NULL);
//	printf("\nlen = %zu\n", ft_strlen("|                                                                               1") - 2);
//	printf("\nlen PTF = %zu\n", ft_strlen("|                                                                               1") - 2);
	free(str);
	return (spaces);
}	

char 	*str_precision(char *str, long precision)
{
	char	*new;
	int		i;
	
//	printf("%lu\n", precision);
	if ((long)ft_strlen(str) < precision || !precision)
		return (str);
	if (!(new = (char *)malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	i = -1;
	while (str[++i] && i < (int)precision)
		new[i] = str[i];
	new[i] = '\0';
	free(str);
	return (new);

}

int		ft_print_string(t_ptf *percents)
{
	char *str;
	
	if (!(str = ft_strdup(percents->a_t.a_string)))
		return (FALSE);
	if (!(str = str_precision(str, percents->precision)))
		return (FALSE);
	if (percents->width > (long)ft_strlen(percents->a_t.a_string) 
			&& ft_ischar(percents->options, '-') != 1)
	{
		if (!(str = str_width(str, percents->width, 0)))
			return (FALSE);
	}
	else if (percents->width <= 0 || (ft_ischar(percents->options, '-') == 1))
		if (!(str = str_width(str, percents->width, 1)))
			return (FALSE);
	ft_putstr(str);
//	printf(""_RED"%s"_END"", str);
	percents->size = ft_strlen(str);
	free(str);
	return (FALSE);
}

/* PRINT ADDRESS */

int		ft_print_address(t_ptf *percents)
{
	char *str;

	if (!(str = ft_strdup(ft_itoa_base((long)percents->a_t.a_ptr, 16))))
		return (FALSE);
//	printf("\nstr = %s\n", str);
//	printf("printf prog = %p\n", percents->a_t.a_ptr);
	percents->size = ft_strlen(str) + 2;
	ft_putstr("0x");
	ft_putstr(str);
//	printf("\n\n");
	free(str);
	return (TRUE);
}

/* PRINT DECIMAL */

int		print_longlong(t_ptf *percents)
{
	char *str;
	
	if (!(str = ft_ltoa(percents->a_t.a_llong)))
		return (-1);


	ft_putstr(str);
	percents->size = ft_strlen(str);
	free(str);
	return (TRUE);


}

int		print_long(t_ptf *percents)
{
	char *str;

	if ((percents->flags + 1) && ((*percents->flags + 1) == 'l'))
		return (print_longlong(percents));
	if (!(str = ft_ltoa(percents->a_t.a_long)))
		return (FALSE);


	ft_putstr(str);
	percents->size = ft_strlen(str);
	free(str);
	return (TRUE);
		

}

int		ft_print_decimal(t_ptf *percents)
{
	char *str;

	if (ft_ischar(percents->flags, 'l') == 1)
		return (print_long(percents));
//	percents->size = ft_strlen(ft_itoa(va_arg(arg, int)));	
//	str = (char *)malloc(sizeof(char) * percents->size + 1);

//	printf("var = %i\n", percents->a_t.a_int);
	str = ft_itoa(percents->a_t.a_int);
//	ft_putstr(ft_width_precision(str, percents, percents->size));
	printf("\n"_RED"HEREEE"_END"\n");
	ft_putstr(str);
	printf("\n"_RED"HEREEE"_END"\n");
	free(str);
	return (TRUE);
}

///* PRINT INTEGER */
//
//int		ft_print_integer(t_ptf *percents)
//{
//	char *str;
//
//	percents->size = ft_strlen(ft_itoa(va_arg(arg, int)));
//	str = (char *)malloc(sizeof(char) * percents->size + 1);
//	str = ft_itoa(va_arg(arg, int));
//	ft_putstr(ft_width_precision(str, percents, percents->size));
//	return (TRUE);
//}
//
///* PRINT OCTAL */
//
//int		ft_print_octal(t_ptf *percents)
//{
//	char *str;
//
//	percents->size = ft_strlen(ft_itoa(va_arg(arg, int)));
//	str = (char *)malloc(sizeof(char) * percents->size + 1);
//	str = ft_itoa_base(va_arg(arg, int), 8);
//	ft_hashtag_flag(percents);
//	ft_zero_flag(percents, percents->size);
//	ft_putstr(str);
//	ft_minus_flag(percents, percents->size);
//	return (TRUE);
//}
//
///* PRINT UNSIGNED */
//
//int		ft_print_unsigned(t_ptf *percents)
//{
//	char *str;
//
//	percents->size = ft_strlen(ft_itoa(va_arg(arg, int)));
//	str = (char *)malloc(sizeof(char) * percents->size + 1);
//	str = ft_itoa_base(va_arg(arg, int), 10);
//	ft_hashtag_flag(percents);
//	ft_zero_flag(percents, percents->size);
//	ft_putstr(str);
//	ft_minus_flag(percents, percents->size);
//	return (TRUE);
//}
//
///* PRINT HEXA */
//
//int		ft_print_hexa(t_ptf *percents)
//{
//	char *str;
//
//	percents->size = ft_strlen(ft_itoa(va_arg(arg, int)));
//	str = (char *)malloc(sizeof(char) * percents->size + 1);
//	str = ft_itoa_base(va_arg(arg, int), 16);
//	ft_hashtag_flag(percents);
//	ft_zero_flag(percents, percents->size);
//	ft_putstr(str);
//	ft_minus_flag(percents, percents->size);
//	return (TRUE);
//}
//
///* PRINT HEXA MAJ */
//
//int		ft_print_hexa_maj(t_ptf *percents)
//{
//	char *str;
//	int i;
//
//	percents->size = ft_strlen(ft_itoa_base(va_arg(arg, int), 16));
//	str = (char *)malloc(sizeof(char) * percents->size + 1);
//	str = ft_itoa_base(va_arg(arg, int), 16);
//	i = 0;
//	while (str[i])
//	{
//		if (str[i] >= 'a' && str[i] <= 'z')
//			str[i] = str[i] - 32;
//		i++;
//	}
//	ft_putstr(ft_width_precision(str, percents, percents->size));
//	return (TRUE);
//}
//
///* PRINT FLOAT */
//
//int		ft_print_float(t_ptf *percents)
//{
//	char *str;
//	int i;
//
//	i = 0;
//	str = ft_ftoa(va_arg(arg, double));
//
//	if (!percents->precision)
//		percents->precision = 6;
//	if (percents->precision)
//		if (str[percents->precision] > 5 + '0')
//		{
//			str[i] = 0 + '0';
//			str[i - 1] += 1 + '0';
//		}
//	ft_strncat(str, "\0", percents->precision + 1);
//
//	ft_putstr(str);
//	return (TRUE);
//}
//
//
