#include <stdio.h>
#include "../../includes/ft_printf.h"


int		main(void)
{
	unsigned int o41 = 19120;
	unsigned int o40 = 1170;
	unsigned int o33 = 10379;
	unsigned int o32 = 30576;
	unsigned int o31 = 12799;
	unsigned int o30 = 6776;
	unsigned int o23 = 23838;
	unsigned int o22 = 20016;
	unsigned int o21 = 6271;
	unsigned int o20 = 13212;
	unsigned int o13 = 30141;
	unsigned int o12 = 12965;
	unsigned int o11 = 15701;
	unsigned int o10 = 20798;
	unsigned int o03 = 5192;
	unsigned int o02 = 28585;
	unsigned int o01 = 14013;
	unsigned int o00 = 717;

ft_printf(""_BBLUE"o"_END" "_MAGENTA"717"_END" >"_CYAN"-5.20ll"_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN""_END"<; = %-5.20llo\n"_BBLUE"o"_END" "_MAGENTA"14013"_END" >"_CYAN" 18l"_END"<; = % 18lo\n"_BBLUE"o"_END" "_MAGENTA"28585"_END" >"_CYAN"-16.10l"_END"<; = %-16.10lo\n"_BBLUE"o"_END" "_MAGENTA"5192"_END" >"_CYAN" ll"_END"<; = % llo\n", o00,o01,o02,o03);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"20798"_END" >"_CYAN""_END"<; = %o\n"_BBLUE"o"_END" "_MAGENTA"15701"_END" >"_CYAN""_END"<; = %o\n"_BBLUE"o"_END" "_MAGENTA"12965"_END" >"_CYAN""_END"<; = %o\n"_BBLUE"o"_END" "_MAGENTA"30141"_END" >"_CYAN"06h"_END"<; = %06ho\n", o10,o11,o12,o13);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"13212"_END" >"_CYAN"#7ll"_END"<; = %#7llo\n"_BBLUE"o"_END" "_MAGENTA"6271"_END" >"_CYAN"07h"_END"<; = %07ho\n"_BBLUE"o"_END" "_MAGENTA"20016"_END" >"_CYAN""_END"<; = %o\n"_BBLUE"o"_END" "_MAGENTA"23838"_END" >"_CYAN""_END"<; = %o\n", o20,o21,o22,o23);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"6776"_END" >"_CYAN""_END"<; = %o\n"_BBLUE"o"_END" "_MAGENTA"12799"_END" >"_CYAN"-10.24hh"_END"<; = %-10.24hho\n"_BBLUE"o"_END" "_MAGENTA"30576"_END" >"_CYAN"-19.34hh"_END"<; = %-19.34hho\n"_BBLUE"o"_END" "_MAGENTA"10379"_END" >"_CYAN" .45l"_END"<; = % .45lo\n", o30,o31,o32,o33);
ft_printf(""_BBLUE"o"_END" "_MAGENTA"1170"_END" >"_CYAN""_END"<; = %o\n"_BBLUE"o"_END" "_MAGENTA"19120"_END" >"_CYAN""_END"<; = %o\n", o40,o41);
	return (0);
}
