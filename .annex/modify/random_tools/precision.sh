#!/bin/sh

flag=$1
precision=$[ ( RANDOM % 3 ) + 1 ]
	if [[ $precision == 1 ]];then
		flag+="";
	elif [[ $precision == 2 ]];then
		flag+=.$[ ( RANDOM % 12 ) + 1 ]
	elif [[ $precision == 3 ]];then
		flag+=.$[ ( RANDOM % 50 ) + 1 ]
	fi
export flag
