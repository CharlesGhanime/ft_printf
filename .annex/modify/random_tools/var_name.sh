#!/bin/sh

if [ \( "$1" = "c" \) ];then
	chosen_name="c$2";
elif [  \( "$1" = "s" \) ];then
	chosen_name="str$2";
elif [  \( "$1" = "p" \) ];then
	chosen_name="ptr$2";
elif [  \( "$1" = "d" \) ];then
	chosen_name="d$2";
elif [  \( "$1" = "i" \) ];then
	chosen_name="i$2";
elif [  \( "$1" = "o" \) ];then
	chosen_name="o$2";
elif [  \( "$1" = "u" \) ];then
	chosen_name="u$2";
elif [  \( "$1" = "x" \) ];then
	chosen_name="x$2";
elif [  \( "$1" = "f" \) ];then
	chosen_name="f$2";
elif [  \( "$1" = "X" \) ];then
	chosen_name="X$2";
fi
export chosen_name
