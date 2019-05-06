#!/bin/sh

declare -a var=()
if [ "$1" = "s" ];then
	flag=$[ ( RANDOM % 4 ) + 1 ]
	if [ "$flag" == 1 ];then
		var=([0]="\"how do you feel about this\";");
	elif [ "$flag" == 2 ];then
		var=([0]="\"		1,2, salmy the salmon\";");
	elif [ "$flag" == 3 ];then
		var=([0]="\"Le panpsychisme est une conception philosophique selon laquelle l'esprit est une propriete ou un aspect fondamental du monde qui s'y presente partout. L'esprit se deploierait ainsi dans toute l'etendue de l'Univers.\";");
	elif [ "$flag" == 4 ];then
		var=([0]="\"Hauntology (a portmanteau of haunting and ontology[1]) is a concept coined by philosopher Jacques Derrida in his 1993 book Spectres of Marx.\";");
	fi
elif [[ "$1" = ["dif"] ]];then
	var=$[ ( RANDOM % 2147483647) - 15000 ]
	var=$var\;
elif [[ "$1" = ["ouxX"] ]];then
	var=$[ ( RANDOM % 33000 ) + 1 ]
	var=$var\;
elif [ "$1" = "c" ];then
	flag=$[ ( RANDOM % 2 ) + 1 ]
	if [ "$flag" == 1 ];then
		var=([0]="\'c\';");
	elif [ "$flag" == 2 ];then
		var=([0]="\'o\';");
	fi
elif [ "$1" = "p" ];then
	var=([0]="NULL;");
fi
export var
