#!/bin/sh

if [[ "$1" == "" ]];then
	flag=$[ ( RANDOM % 10 ) + 1 ]
	if [  \( "$flag" == 1 \) ];then
		conv="c";
	elif [  \( "$flag" == 2 \) ];then
		conv="s";
	elif [  \( "$flag" == 3 \) ];then
		conv="p";
	elif [  \( "$flag" == 4 \) ];then
		conv="d";
	elif [  \( "$flag" == 5 \) ];then
		conv="i";
	elif [  \( "$flag" == 6 \) ];then
		conv="o";
	elif [  \( "$flag" == 7 \) ];then
		conv="u";
	elif [  \( "$flag" == 8 \) ];then
		conv="x";
	elif [  \( "$flag" == 9 \) ];then
		conv="f";
	elif [  \( "$flag" == 10 \) ];then
		conv="X";
	fi
else 
	conv="$1"
fi
export conv
