#!/bin/bash

echo "\tPRINTF FUZZER PERSONALIZER RANDOMIZER ATOMIZER NUCLEARISER"
while true; do
	echo "Select an option:"
	echo " [1] Quick"
	echo " [2] Quick10"
	echo " [3] Customize"
	echo " [h] help"
	echo " [42]"

	read -p "" mode_select
	case $mode_select in
		[1]* ) 	echo "4 lignes with 3 to 5 printfs per line. Random variables, flags and color";
			selection=1;
			break;;
		[2]* ) echo "10 printfs on one line with random variables, flags and colors";
			selection=2;
			break;;
		[3]* ) selection=;
			break;;
		[h]* ) echo "\n";
			echo "------------------------------------------------------------------------------------";
			echo "[1] Quick sets up 3 to 5 printf lines with 4 printfs per line, random variables and with colors.";
			sleep 1;
			echo "[2] Quick10 sets up one printf line with 10 printfs inside it, random variables and with colors.";
			sleep 1;
			echo "[3] Customize allows you to choose the number of lines, the conversion specifier, if you want random flags and colors";
			echo "-------------------------------------------------------------------------------------";
			echo "\n";
			sleep 2;;
		[42]* ) . .annex/modify/options/42.sh
	esac
done

export selection
