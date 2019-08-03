#include <stdio.h>
#include "../../includes/ft_printf.h"


int		main(void)
{
	int	test;
	char	*prout;
	char	*str;
	void *ptr10 = &test;
	void *ptr03 = prout;
	void *ptr02 = str;
	void *ptr01;
	void *ptr00 = NULL;

printf("p NULL; = %p\np NULL ><; = %p\np NULL; = %p\np NULL ><; = %p\n", ptr00,ptr01,&ptr02,&ptr03);
printf("p NULL; = %p\n", (char *)ptr10);

ft_printf("p NULL; = %p\np NULL ><; = %p\np NULL; = %p\np NULL ><; = %p\n", ptr00,ptr01,&ptr02,&ptr03);
ft_printf("p NULL; = %p\n", (char *)ptr10);
return (0);
}
