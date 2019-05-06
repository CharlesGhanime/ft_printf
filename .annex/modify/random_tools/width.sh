#!/bin/bash

flag=$1
width=$[ ( RANDOM % 4 ) + 2 ]
	if [ $width == "1" ];then
		flag+="";
	elif [ $width == "2" ];then
		flag+=$[ ( RANDOM % 5 ) + 1 ];
	elif [ $width == "3" ];then
		flag+=$[ ( RANDOM % 10 ) + 3 ];
	elif [ $width == "4" ];then
		flag+=$[ ( RANDOM % 15 ) + 5 ];
	fi
export flag
