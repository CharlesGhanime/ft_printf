/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:00:22 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/19 18:49:24 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
#include <stdio.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** PART I FUNCTIONS
*/

void				*ft_memset(void *str, int c, size_t len);
void				ft_bzero(void *str, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
size_t				ft_strlen(char *s);
char				*ft_strdup(char *s1);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strncpy(char *dst, char *src, size_t len);
char				*ft_strcat(char *dst, char *src);
char				*ft_strncat(char *dst, char *src, size_t len);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
char				*ft_strchr(char *s, int c);
char				*ft_strrchr(char *s, int c);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(char *haystack, char *needle,
					size_t len);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, size_t len);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_ischar(char *str, char c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** PART II FUNCTIONS
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
int					ft_strequ(char *s1, char *s2);
int					ft_strnequ(char *s1, char *s2, size_t n);
char				*ft_strsub(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s);
char				**ft_strsplit(char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** ADDED FUNCTIONS
*/

char				*ft_strndup(char *src, unsigned int n);
int					ft_isupper(int c);
int					ft_islower(int c);
void				ft_swap(int *a, int *b);
void				ft_ft(int *nbr);
int					ft_is_sort(int *tab, size_t length, int (*f)(int, int));
char				*ft_strrev(char *str);
void				ft_is_negative(int n);
int					ft_counter(int n);
int					ft_wordcounter(char const *s, char c);
char				**ft_filling(char *s, char c, char **tab);
char				*ft_addonechar(char **str, char c);
void				ft_putnbr_base(unsigned int nb, unsigned int base);
char				*ft_itoa_base(unsigned int nb, unsigned int base);
char                *ft_ftoa(double myfloat);

/*
** BONUS SINGLY-LINKED LISTS
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
