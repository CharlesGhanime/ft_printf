#include <stdio.h>
#include "../includes/ft_printf.h"


int		main(void)
{
	char c41 = 'c';
	unsigned int u40 = 30731;
	char c33 = 'c';
	unsigned int x32 = 6752;
	unsigned int o31 = 15370;
	unsigned int u30 = 7382;
	unsigned int o20 = 101;
	unsigned int X12 = 13195;
	unsigned int X11 = 11958;
	unsigned int o10 = 17625;
	char str01[400] = "Hauntology (a portmanteau of haunting and ontology[1]) is a concept coined by philosopher Jacques Derrida in his 1993 book Spectres of Marx.";
	char str00[400] = "how do you feel about this";

ft_printf("s how do you feel about this = %s\ns Hauntology (a portmanteau of haunting and ontology[1]) is a concept coined by philosopher Jacques Derrida in his 1993 book Spectres of Marx. = %s\n", str00,str01);
ft_printf("o 17625; = %o\nX 11958 ><; = %X\nX 13195; = %X\n", o10,X11,X12);
ft_printf("o 101 ><; = %o\n", o20);
ft_printf("u 7382; = %u\no 15370; = %o\nx 6752 ><; = %x\nc 'c' >#4.42h<; = %#4.42hc\n", u30,o31,x32,c33);
ft_printf("u 30731 >#.42hh<; = %#.42hhu\nc 'c' >-3.25l > >+.14l >+4.5h<; = %+4.5h+.14l-3.25lc\n", u40,c41);
	return (0);
}
