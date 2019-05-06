#!/bin/bash

echo "\nDon't panic.\n"

fun_fact=$[ ( RANDOM % 10 ) + 1 ]

if [[ $fun_fact = 1 ]];then
	echo "is it all about burgers here"
	open "https://en.wikipedia.org/wiki/Huge-LQG" 
elif [[ $fun_fact = 2 ]];then
	echo "how do you compare two bricks?"
	open "https://en.wikipedia.org/wiki/Hercules%E2%80%93Corona_Borealis_Great_Wall"
elif [[ $fun_fact = 3 ]];then
	echo "last night, i realized how far the supermarket was"
	open "https://en.wikipedia.org/wiki/Laniakea_Supercluster" 
elif [[ $fun_fact = 4 ]];then
	echo "well don't take pride for it, just go with the flow"
	open "https://en.wikipedia.org/wiki/Hydra-Centaurus_Supercluster"
elif [[ $fun_fact = 5 ]];then
	open "https://en.wikipedia.org/wiki/Great_Attractor"
elif [[ $fun_fact = 6 ]];then
	open "https://en.wikipedia.org/wiki/Zone_of_Avoidance"
elif [[ $fun_fact = 7 ]];then
	open "https://en.wikipedia.org/wiki/Sloan_Great_Wall"
elif [[ $fun_fact = 8 ]];then
	open "https://en.wikipedia.org/wiki/BOSS_Great_Wall"
elif [[ $fun_fact = 9 ]];then
	open "https://fr.wikipedia.org/wiki/Canard"
elif [[ $fun_fact = 10 ]]; then
	open "https://www.youtube.com/watch?v=aboZctrHfK8&t=1s"
fi

while ! [[ $continue = [YyNn] ]]; do
	read -p "-still need me ? [yn]" continue;
	if [[ $continue = [Yy] ]]; then
		echo "-aight bra\n"
	elif [[ $continue == [Nn] ]]; then
		exit
	else
		echo "don't be a fool of yourself";
	fi
done

