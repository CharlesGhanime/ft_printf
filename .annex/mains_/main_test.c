#include <stdio.h>
#include "../../includes/ft_printf.h"


int		main(void)
{
	unsigned int o40 = 222;
	unsigned int o32 = 26890;
	unsigned int o31 = 14901;
	unsigned int o30 = 28039;
	unsigned int o22 = 16885;
	unsigned int o21 = 31170;
	unsigned int o20 = 6052;
	unsigned int o12 = 2579;
	unsigned int o11 = 19999;
	unsigned int o10 = 2805;
	unsigned int o00 = 19413;

ft_printf(""_BBLUE"o"_END" "_MAGENTA"19413;"_END" = %o\n", o00);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"2805;"_END" = %o\n"_BBLUE"o"_END" "_MAGENTA"19999;"_END" = %o\n"_BBLUE"o"_END" "_MAGENTA"2579;"_END" = %o\n", o10,o11,o12);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"6052;"_END" = %o\n"_BBLUE"o"_END" "_MAGENTA"31170;"_END" = %o\n"_BBLUE"o"_END" "_MAGENTA"16885;"_END" = %o\n", o20,o21,o22);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"28039;"_END" = %o\n"_BBLUE"o"_END" "_MAGENTA"14901;"_END" = %o\n"_BBLUE"o"_END" "_MAGENTA"26890;"_END" = %o\n", o30,o31,o32);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"222;"_END" = %o\n", o40);
	return (0);
}
