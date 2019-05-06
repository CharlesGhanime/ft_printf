#!/bin/sh

declare -a designation=()
if [ \( "$1" == "c" \) ];then
	designation=([0]="char c"$2"");
elif [  \( "$1" == "s" \) ];then
	designation=([0]="char str"$2"[400]");
elif [  \( "$1" == "p" \) ];then
	designation=([0]="void *ptr"$2"");
elif [  \( "$1" == "d" \) ];then
	designation=([0]="int d"$2"");
elif [  \( "$1" == "i" \) ];then
	designation=([0]="int i"$2"");
elif [  \( "$1" == "o" \) ];then
	designation=([0]="unsigned int o"$2"");
elif [  \( "$1" == "u" \) ];then
	designation=([0]="unsigned int u"$2"");
elif [  \( "$1" == "x" \) ];then
	designation=([0]="unsigned int x"$2"");
elif [  \( "$1" == "f" \) ];then
	designation=([0]="float f"$2"");
elif [  \( "$1" == "X" \) ];then
	designation=([0]="unsigned int X"$2"");
fi
export designation

