#!/bin/bash

main_test=.annex/mains_/main_test.c

if [[ $1 == [12] ]]; then
	break;
else
	while true; do
		read -p "Do you want to have colors in the printing? [y/n] " yn
		case $yn in
			[Yy]* ) break;;
			[Nn]* ) sed -i '' 's/"_END"//g' $main_test
				sed -i '' 's/"_RED"//g' $main_test
				sed -i '' 's/"_CYAN"//g' $main_test
				sed -i '' 's/"_BBLUE"//g' $main_test
				sed -i '' 's/"_MAGENTA"//g' $main_test
				break;;
			* ) echo "Please answer yes or no, no joke this time";;
		esac
	done
fi
