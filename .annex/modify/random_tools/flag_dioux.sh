#!/bin/sh

flag=$1
rand=$[ ( RANDOM % 4 ) + 1 ]
if [ \( "$rand" == 1 \) ];then
	flag+="hh";
elif [ \( "$rand" == 2 \) ];then
	flag+="h";
elif [  \( "$rand" == 3 \) ];then
	flag+="l";
elif [  \( "$rand" == 4 \) ];then
	flag+="ll";
#elif [  \( "$rand" == 5 \) ];then
#	flag+="L";
fi
export flag
