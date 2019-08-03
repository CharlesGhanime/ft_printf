/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aff_reforged.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:35:39 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/04 01:36:54 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"


//int		get_token(t_ptf *percents) 
//{
//	int token;
//
//	token = 0;
//	if (percents->width > (long)ft_strlen(percents->a_t.a_string) 
//			&& ft_ischar(percents->options, '-') != 1)
//		token = 0;
//	else if (percents->width <= 0 || (ft_ischar(percents->options, '-') == 1))
//		token = 1;
//	return (token);
//}

char	*str_width(char *str, long width, t_ptf *percents, char c)
{
	char 	*new;
	char	*tmp;
	int 	token;

	tmp = NULL;
	if (!(new = ft_fillchar(width, (long)ft_strlen(str), c)))
		return (NULL);
//	token = get_token(percents);
//	if (token == 0)
//	{
		if (!(tmp = ft_strjoin(new, str)))
			return (NULL);
//	}
//	else if (token == 1)
//		if (!(tmp = ft_strjoin(str, new)))
//			return (NULL);
	free(new);
	new = ft_strdup(tmp);
	free(tmp);
	return (new);
}	

/* PRINT ADDRESS */

int		ft_print_address(t_ptf *percents)
{
	char *str;

	if (!(str = ft_strdup(ft_itoa_base((long)percents->a_t.a_ptr, "0123456789abcdef"))))
		return (FALSE);
//	printf("retour de ft_itoa_base = %s\n", str);
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

char	*get_int_var(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (ft_ischar(percents->flags, 'l') == 1)
	{	
		if (*(percents->flags + 1) == 'l')
		{
			if (!(str = ft_ltoa(percents->a_t.a_llong)))
				return (NULL);
			percents->a_t.a_llong >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		}
		else 
		{
			if (!(str = ft_ltoa(percents->a_t.a_long)))
				return (NULL);
			percents->a_t.a_long >= 0 ? (percents->signe = '+') : (percents->signe = '-');
		}
	}
	else 
	{
		if (!(str = ft_itoa(percents->a_t.a_int)))
			return (NULL);
		percents->a_t.a_int >= 0 ? (percents->signe = '+') : (percents->signe = '-');
	}	
	return (str);
}

int		count_pos(char *str, int token)
{
	int pos;

	pos = 0;
	if (token == 0)
		while (str[pos + 1] == ' ' || str[pos + 1] == '0')
			pos++;
	else if (token == 1)
		while (str[pos + 1] == ' ')
			pos++;
	return (pos);
}

char 	*str_precision(char *str, long precision)
{
	char	*new;
	int		i;
	
//	printf("%lu\n", precision);
	if (!precision || (long)ft_strlen(str) < precision)
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

char 	*int_precision(char *str, long precision, int len, t_ptf *percents)
{
	char	*new;
	int 	i;
	
	if ((!precision || (int)precision < len))
		return (str);
	if (!(new = (char *)malloc(sizeof(char) * (precision + len + 1))))
		return (NULL);
	i = -1;
//	printf("WOOW1 == %s\n", new);
	while (++i < ((int)precision - len))
		new[i] = '0';
	new[i] = '\0';
//	printf("WOOW2 == %s\n", new);
	new = ft_strcat(new, str);
	free(str);
	return (new);
}

char	*manage_opts(char *str, t_ptf *percents)
{
	int		pos;
	char	*new;

	new = NULL;
//	printf("manage str = %s\n", str);
	if (percents->options & HASH && (percents->conv == 'x' || percents->conv == 'X' 
				|| percents->conv == 'o' ))
		;  												// input funct to manage HASH
	if (percents->options & ZERO && !percents->precision && !(percents->options & MINUS))
		;												// call ft_padding 
	if (percents->options & MINUS)
		;												// call ft_padding
	if (percents->options & SPACE && !(percents->options & PLUS) && 
			!(percents->unsignd) && (percents->signe == '+' || !str))
		new = ft_addonecharpos(&str, ' ', 0);					// add one space
	if (percents->options & PLUS && !(percents->unsignd))
		new = ft_strjoinfrchoz(&percents->signe, str, 2);		// print sign


	if (!new)
		return (str);
	return (new);
}

int		ft_print_decimal(t_ptf *percents)
{
	char *str;

	str = NULL;
	if (!(str = get_int_var(percents)))
		return (FALSE);
//	printf("\nITIZ == %s\n", str); 
	if (!(str = int_precision(str, percents->precision, (int)ft_strlen(str), percents)))
	   return (FALSE);
//	printf("\nITIZ2 == %s\n", str); 
	if (!(str = manage_opts(str, percents)))
		return (FALSE);
//	printf("\nITIZ3 == %s\n", str); 


	percents->size = ft_strlen(str);
//	printf("\n"_RED"HEREEE"_END"\n");
	ft_putstr(str);
	free(str);
	return (TRUE);
}


//char 	*int_precision(char *str, long precision)
//{
//	char *new;
//	int i;
//	int diff;
//
//	if (!precision || precision < ft_strlen(str))
//		return (str);
//	if (!(new = (char *)malloc(sizeof(char) * precision + 1)))
//	i = -1;
//	if (!(new = 
//	diff = (size_t)precision - ft_strlen(str);
//	while (str[++i] && i < (int)precision)
//	{			
//	}	
//
//	return (new);
//}

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
