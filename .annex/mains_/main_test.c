#include <stdio.h>
#include "../../includes/ft_printf.h"


int		main(void)
{
	float f92 = 16145;
	float f91 = -8201;
	float f90 = 17023;
	float f80 = -10666;
	float f72 = 7655;
	float f71 = 3506;
	float f70 = -5730;
	float f63 = 15461;
	float f62 = -3812;
	float f61 = -7531;
	float f60 = 5973;
	float f50 = 5968;
	float f42 = -8915;
	float f41 = 11471;
	float f40 = -4022;
	float f31 = 13314;
	float f30 = 16636;
	float f20 = -8519;
	float f12 = -13212;
	float f11 = 12900;
	float f10 = 11248;
	float f01 = 4565;
	float f00 = -2890;

ft_printf(""_BBLUE"f"_END" "_MAGENTA"-2890"_END" >"_CYAN" .22l"_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN"#11.8l"_END" >"_CYAN""_END" >"_CYAN"05.21L"_END" >"_CYAN""_END" >"_CYAN""_END" >"_CYAN"-6.1L"_END" >"_CYAN""_END"<; = %-6.1L05.21L#11.8l .22lf\n"_BBLUE"f"_END" "_MAGENTA"4565"_END" >"_CYAN"+8.10L"_END"<; = %+8.10Lf\n", f00,f01);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"11248"_END" >"_CYAN""_END"<; = %f\n"_BBLUE"f"_END" "_MAGENTA"12900"_END" >"_CYAN"+.1l"_END"<; = %+.1lf\n"_BBLUE"f"_END" "_MAGENTA"-13212"_END" >"_CYAN""_END"<; = %f\n", f10,f11,f12);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"-8519"_END" >"_CYAN"#10.24L"_END"<; = %#10.24Lf\n", f20);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"16636"_END" >"_CYAN"#L"_END"<; = %#Lf\n"_BBLUE"f"_END" "_MAGENTA"13314"_END" >"_CYAN""_END"<; = %f\n", f30,f31);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"-4022"_END" >"_CYAN"+.4l"_END"<; = %+.4lf\n"_BBLUE"f"_END" "_MAGENTA"11471"_END" >"_CYAN""_END"<; = %f\n"_BBLUE"f"_END" "_MAGENTA"-8915"_END" >"_CYAN""_END"<; = %f\n", f40,f41,f42);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"5968"_END" >"_CYAN" l"_END"<; = % lf\n", f50);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"5973"_END" >"_CYAN""_END"<; = %f\n"_BBLUE"f"_END" "_MAGENTA"-7531"_END" >"_CYAN""_END"<; = %f\n"_BBLUE"f"_END" "_MAGENTA"-3812"_END" >"_CYAN" l"_END"<; = % lf\n"_BBLUE"f"_END" "_MAGENTA"15461"_END" >"_CYAN"0.8L"_END"<; = %0.8Lf\n", f60,f61,f62,f63);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"-5730"_END" >"_CYAN""_END"<; = %f\n"_BBLUE"f"_END" "_MAGENTA"3506"_END" >"_CYAN""_END"<; = %f\n"_BBLUE"f"_END" "_MAGENTA"7655"_END" >"_CYAN"010l"_END"<; = %010lf\n", f70,f71,f72);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"-10666"_END" >"_CYAN""_END"<; = %f\n", f80);
ft_printf(""_BBLUE"f"_END" "_MAGENTA"17023"_END" >"_CYAN"#14L"_END"<; = %#14Lf\n"_BBLUE"f"_END" "_MAGENTA"-8201"_END" >"_CYAN"-13.50L"_END"<; = %-13.50Lf\n"_BBLUE"f"_END" "_MAGENTA"16145"_END" >"_CYAN""_END"<; = %f\n", f90,f91,f92);
	return (0);
}
