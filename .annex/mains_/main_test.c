#include <stdio.h>
#include "../../includes/ft_printf.h"


int		main(void)
{
	int d32 = 14789;
	int d31 = -9938;
	int d30 = 10478;
	int d22 = 4795;
	int d21 = -14309;
	int d20 = 6688;
	int d11 = -2125;
	int d10 = -5454;
	int d03 = -14836;
	int d02 = 2952;
	int d01 = -3576;
	int d00 = 5425;

ft_printf(""_BBLUE"d"_END" "_MAGENTA"5425"_END" >"_CYAN"+.23ll"_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN""_END"<; = %+.23lld\n"_BBLUE"d"_END" "_MAGENTA"-3576"_END" >"_CYAN"-hh"_END"<; = %-hhd\n"_BBLUE"d"_END" "_MAGENTA"2952"_END" >"_CYAN" .36ll"_END"<; = % .36lld\n"_BBLUE"d"_END" "_MAGENTA"-14836"_END" >"_CYAN"-4hh"_END"<; = %-4hhd\n", d00,d01,d02,d03);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"-5454"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"-2125"_END" >"_CYAN""_END"<; = %d\n", d10,d11);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"6688"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"-14309"_END" >"_CYAN" 9.8l"_END"<; = % 9.8ld\n"_BBLUE"d"_END" "_MAGENTA"4795"_END" >"_CYAN"#1.7l"_END"<; = %#1.7ld\n", d20,d21,d22);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"10478"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"-9938"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"14789"_END" >"_CYAN"#5.42l"_END"<; = %#5.42ld\n", d30,d31,d32);
	return (0);
}
