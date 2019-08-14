#include <stdio.h>
#include "../../includes/ft_printf.h"


int		main(void)
{
	unsigned int x91 = 7270;
	unsigned int x90 = 18457;
	unsigned int x82 = 16664;
	unsigned int x81 = 21540;
	unsigned int x80 = 16605;
	unsigned int x73 = 29246;
	unsigned int x72 = 7925;
	unsigned int x71 = 7379;
	unsigned int x70 = 17252;
	unsigned int x60 = 290;
	unsigned int x52 = 22559;
	unsigned int x51 = 27820;
	unsigned int x50 = 14716;
	unsigned int x43 = 26630;
	unsigned int x42 = 8355;
	unsigned int x41 = 14402;
	unsigned int x40 = 11373;
	unsigned int x30 = 18375;
	unsigned int x20 = 28737;
	unsigned int x12 = 574;
	unsigned int x11 = 8909;
	unsigned int x10 = 20436;
	unsigned int x01 = 2598;
	unsigned int x00 = 5307;

ft_printf(""_BBLUE"x"_END" "_MAGENTA"5307"_END" >"_CYAN"#7.7h"_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN"02.9l"_END" >"_CYAN""_END" >"_CYAN"-.20l"_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN"+12ll"_END" >"_CYAN""_END"<; = %+12ll-.20l02.9l#7.7hx\n"_BBLUE"x"_END" "_MAGENTA"2598"_END" >"_CYAN"#6h"_END"<; = %#6hx\n", x00,x01);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"20436"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"x"_END" "_MAGENTA"8909"_END" >"_CYAN"04h"_END"<; = %04hx\n"_BBLUE"x"_END" "_MAGENTA"574"_END" >"_CYAN""_END"<; = %x\n", x10,x11,x12);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"28737"_END" >"_CYAN"#3h"_END"<; = %#3hx\n", x20);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"18375"_END" >"_CYAN" 1l"_END"<; = % 1lx\n", x30);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"11373"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"x"_END" "_MAGENTA"14402"_END" >"_CYAN"+5h"_END"<; = %+5hx\n"_BBLUE"x"_END" "_MAGENTA"8355"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"x"_END" "_MAGENTA"26630"_END" >"_CYAN""_END"<; = %x\n", x40,x41,x42,x43);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"14716"_END" >"_CYAN" 3.10ll"_END"<; = % 3.10llx\n"_BBLUE"x"_END" "_MAGENTA"27820"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"x"_END" "_MAGENTA"22559"_END" >"_CYAN""_END"<; = %x\n", x50,x51,x52);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"290"_END" >"_CYAN"0hh"_END"<; = %0hhx\n", x60);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"17252"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"x"_END" "_MAGENTA"7379"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"x"_END" "_MAGENTA"7925"_END" >"_CYAN" 1.5hh"_END"<; = % 1.5hhx\n"_BBLUE"x"_END" "_MAGENTA"29246"_END" >"_CYAN""_END"<; = %x\n", x70,x71,x72,x73);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"16605"_END" >"_CYAN"+4h"_END"<; = %+4hx\n"_BBLUE"x"_END" "_MAGENTA"21540"_END" >"_CYAN"08.33h"_END"<; = %08.33hx\n"_BBLUE"x"_END" "_MAGENTA"16664"_END" >"_CYAN""_END"<; = %x\n", x80,x81,x82);
ft_printf(""_BBLUE"x"_END" "_MAGENTA"18457"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"x"_END" "_MAGENTA"7270"_END" >"_CYAN"#16.12l"_END"<; = %#16.12lx\n", x90,x91);
	return (0);
}
