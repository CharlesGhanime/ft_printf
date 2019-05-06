#!/bin/bash

if [[ $1 == [12] ]]; then
	break;
else
	while true; do
		read -p "Do you want to have colors in the printing? [y/n] " yn
		case $yn in
			[Yy]* ) break;;
			[Nn]* ) sed -i '' 's/"_END"//g' .annex/main_test.c
				sed -i '' 's/"_RED"//g' .annex/main_test.c
				sed -i '' 's/"_CYAN"//g' .annex/main_test.c
				sed -i '' 's/"_BBLUE"//g' .annex/main_test.c
				sed -i '' 's/"_MAGENTA"//g' .annex/main_test.c
				break;;
			* ) echo "Please answer yes or no, no joke this time";;
		esac
	done
fi
