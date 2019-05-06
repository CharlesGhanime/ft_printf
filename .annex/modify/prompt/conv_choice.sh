#!/bin/bash

if [[ $1 == [1-2] ]];then
	break;	
else	
	while true; do
		read -p "Would you like to choose a specific conversion indicator or go full random? [choose/random] " yn
		case $yn in
			[Cc]* ) echo "Choose a conversion indicator among \"d, i, o, u, x, X, f, c, s, p\""
				read choice
				if ! [[ $choice = ["diouxXfcsp"] ]];then
					while ! [[ $choice = ["diouxXfcsp"] ]];do
						echo "Choose a conversion indicator among \"d, i, o, u, x, X, f, c, s, p\"."
						read choice
					done
				fi
				echo "Thanks. $line_nb lines have been set up with the $choice conversion indicator."; break;;
			[Rr]* ) echo "Thank you. $line_nb lines have been set up."; break;;
			* ) echo "Please answer choose or random, no joke this time";;
		esac
	done
fi
export choice
