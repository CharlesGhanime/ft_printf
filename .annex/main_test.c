#include <stdio.h>
#include "../includes/ft_printf.h"


int		main(void)
{
	unsigned int x23 = 13064;
	int i22 = -10592;
	unsigned int X21 = 17429;
	unsigned int o20 = 28163;
	int i13 = 2944;
	char str12[400] = "		1,2, salmy the salmon";
	char str11[400] = "how do you feel about this";
	void *ptr10 = NULL;
	char c03 = 'o';
	unsigned int u02 = 13707;
	char str01[400] = "		1,2, salmy the salmon";
	unsigned int o00 = 20857;

ft_printf("o 20857 > 2.21ll<; = % 2.21llo\ns  1,2, salmy the salmon = %s\nu 13707; = %u\nc 'o' ><; = %c\n", o00,str01,u02,c03);
ft_printf("p NULL >#1.26h ><; = %#1.26hp\ns how do you feel about this = %s\ns  1,2, salmy the salmon = %s\ni 2944; = %i\n", ptr10,str11,str12,i13);
ft_printf("o 28163 ><; = %o\nX 17429; = %X\ni -10592 ><; = %i\nx 13064 >+11.12h<; = %+11.12hx\n", o20,X21,i22,x23);
	return (0);
}
