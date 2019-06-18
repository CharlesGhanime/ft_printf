#include <stdio.h>
#include "../includes/ft_printf.h"


int		main(void)
{
	char	*test;
	char	*prout;
	char	*str;
	void *ptr10 = test;
	void *ptr03 = prout;
	void *ptr02 = str;
	void *ptr01 = NULL;
	void *ptr00 = NULL;

ft_printf("p NULL; = %p\np NULL ><; = %p\np NULL; = %p\np NULL ><; = %p\n", ptr00,ptr01,ptr02,ptr03);
//ft_printf("p NULL; = %p\n", ptr10);
	return (0);
}
