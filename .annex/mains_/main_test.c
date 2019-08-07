#include <stdio.h>
#include "../../includes/ft_printf.h"


int		main(void)
{
	int d20 = 10577;
	int d13 = 1094;
	int d12 = 14244;
	int d11 = 5292;
	int d10 = 1026;
	int d02 = -14172;
	int d01 = 729;
	int d00 = -13099;

ft_printf(""_BBLUE"d"_END" "_MAGENTA"-13099"_END" >"_CYAN" 5.37ll"_END" >"_CYAN""_END" >"_CYAN""_END"<; = % 5.37lld\n"_BBLUE"d"_END" "_MAGENTA"729"_END" >"_CYAN"019.3ll"_END"<; = %019.3lld\n"_BBLUE"d"_END" "_MAGENTA"-14172"_END" >"_CYAN"+.6ll"_END"<; = %+.6lld\n", d00,d01,d02);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"1026"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"5292"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"14244"_END" >"_CYAN" 9.11ll"_END"<; = % 9.11lld\n"_BBLUE"d"_END" "_MAGENTA"1094"_END" >"_CYAN" 4.11ll"_END"<; = % 4.11lld\n", d10,d11,d12,d13);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"10577"_END" >"_CYAN""_END"<; = %d\n", d20);
	return (0);
}
