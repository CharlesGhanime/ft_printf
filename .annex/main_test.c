#include <stdio.h>
#include "../includes/ft_printf.h"


int		main(void)
{
	int d43 = 12242;
	int d42 = 4786;
	int d41 = 494;
	int d40 = 11707;
	int d33 = 14343;
	int d32 = 7947;
	int d31 = -665;
	int d30 = 13539;
	int d21 = 61;
	int d20 = -917;
	int d13 = -1080;
	int d12 = 4707;
	int d11 = -8371;
	int d10 = 3224;
	int d00 = -5034;

ft_printf(""_BBLUE"d"_END" "_MAGENTA"-5034"_END" >"_CYAN"#8.7l"_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN""_END"<; = %#8.7ld\n", d00);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"3224"_END" >"_CYAN"-.3h"_END"<; = %-.3hd\n"_BBLUE"d"_END" "_MAGENTA"-8371"_END" >"_CYAN" 1.10l"_END"<; = % 1.10ld\n"_BBLUE"d"_END" "_MAGENTA"4707"_END" >"_CYAN"-.5ll"_END"<; = %-.5lld\n"_BBLUE"d"_END" "_MAGENTA"-1080"_END" >"_CYAN""_END"<; = %d\n", d10,d11,d12,d13);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"-917"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"61"_END" >"_CYAN"#5.24h"_END"<; = %#5.24hd\n", d20,d21);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"13539"_END" >"_CYAN"-ll"_END"<; = %-lld\n"_BBLUE"d"_END" "_MAGENTA"-665"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"7947"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"14343"_END" >"_CYAN"07.29ll"_END"<; = %07.29lld\n", d30,d31,d32,d33);
ft_printf(""_BBLUE"d"_END" "_MAGENTA"11707"_END" >"_CYAN" .11hh"_END"<; = % .11hhd\n"_BBLUE"d"_END" "_MAGENTA"494"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"4786"_END" >"_CYAN""_END"<; = %d\n"_BBLUE"d"_END" "_MAGENTA"12242"_END" >"_CYAN"-12.22hh"_END"<; = %-12.22hhd\n", d40,d41,d42,d43);
	return (0);
}
