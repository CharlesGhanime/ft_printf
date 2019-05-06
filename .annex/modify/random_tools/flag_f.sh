#!/bin/sh

flag=$1
rand=$[ ( RANDOM % 2 ) + 1 ]
if [  \( "$rand" == 1 \) ];then
	flag+="l";
elif [  \( "$rand" == 2 \) ];then
	flag+="L";
elif [ \( "$rand" == 3 \) ];then
	flag+="";
fi
export flag
