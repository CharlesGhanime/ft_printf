#!/bin/bash

selection=$1
if [[ $selection == 1 ]]; then
	line_nb=$[ ( RANDOM % 5 ) + 3 ]
elif [[ $selection == 2 ]]; then
	line_nb=1
else
	re='^[0-9]+$'
	i=0
	choice=""
	echo "Hi, how many printf lines do you want?"
	
	read line_nb
	
	if ! [[ $line_nb =~ "$re" ]];then
		while ! [[ $line_nb =~ $re ]]; do
			if [[ $i = 0 ]];then
				echo "That was not correct, please input a number between 0 and 5 (or more)"
			elif [[ $i = 1 ]];then
				echo "can you read English?"
			elif [[ $i = 2 ]];then
				echo "you life is a lie and your mum a b****"
			elif [[ $i = 3 ]];then
				echo "just fcking get lost, DISAPPEAR!! YOURE NOT WORTH MY TIME"
			elif [[ $i -gt 3 ]];then
				echo "..................."
			fi
			read line_nb
			i=$[$i+1]
		done
	fi
fi

export line_nb
