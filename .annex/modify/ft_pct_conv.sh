#!/bin/bash

#
### CLEANING
#
sed -i '' "/;/d" .annex/real_printf.c
sed -i '' '/^[[:space:]]*$/d' .annex/real_printf.c
awk -v n=3 -v s="\n" 'NR == n {print s} {print}' .annex/real_printf.c > .annex/tmp
cat .annex/tmp > .annex/real_printf.c
perl -0777 -pe 's {\{} {$&\n\treturn (0);}g' .annex/real_printf.c > .annex/tmp
cat .annex/tmp > .annex/real_printf.c
#
### SETTING UP
#
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
		* ) echo "Please answer yes or no, no joke this time";;
    esac
done

#
### INPUTTING
#

i=0
add_var=""
m_var=""
while [[ "$i" -lt "$line_nb" ]]
do
	j=0
	input_pf=""
	var_name=""
	pct_nb=$[ ( RANDOM % 4 ) + 1]
	while [ "$j" -lt "$pct_nb" ]
	do
		var_index="$i$j"
		. .annex/modify/random_tools/conv_select.sh "$choice"
		. .annex/modify/random_tools/variables.sh "${conv}"
		if [[ $conv == 's' ]];then
			m_var=`echo $var | cut -c 2- | rev | cut -c 3- | rev`
			input_pf+="$conv $m_var = %$conv"
		else
			input_pf+="\"_RED\"$conv\"_END\" \"_MAGENTA\"$var\"_END\" = %$conv"	
		fi
		. .annex/modify/random_tools/designation.sh "${conv}" "${var_index}"
		add_var=([0]=""${designation[0]}" = "${var[0]}"")
		perl -0777 -pe "s {\)\n\{} {$&\n\t${add_var[0]}}g" .annex/real_printf.c > .annex/tmp
		cat .annex/tmp > .annex/real_printf.c
		. .annex/modify/random_tools/var_name.sh $conv $var_index
		var_name+="$chosen_name,"
		j=$[$j + 1]
	done
	var_name=`echo $var_name | sed 's/.$//'`
	if [ $i -lt 1 ];then
		awk '/return/{c++;if(c==1){printf "\n"; c=0}} 1' .annex/real_printf.c > .annex/tmp
		cat .annex/tmp > .annex/real_printf.c
	fi
	awk -v input="$input_pf" -v name="$var_name" '
	/return/ {
	c++
	if(c==1) {
		printf "\tft_printf(\"%s\", %s);\n", input, name
		c=1
	}
}
1 { print }' .annex/real_printf.c > .annex/tmp
cat .annex/tmp > .annex/real_printf.c
i=$[$i + 1]
done

sed -i '' 's/%[diouxXfpcs]/&\\n/g' .annex/real_printf.c

while true; do
	read -p "Do you also want to generate random flags, options, width... for your variables? [y/n] " yn
	case $yn in
		[Yy]* ) sh .annex/modify/change_flags.sh; break;;
		[Nn]* ) break;;
		* ) echo "Please answer yes or no, no joke this time";;
	esac
done
while true; do
	read -p "Do you want to have colors in the printing? [y/n] " yn
	case $yn in
		[Yy]* ) break;;
		[Nn]* ) sed -i '' 's/"_END"//g' .annex/real_printf.c
				sed -i '' 's/"_RED"//g' .annex/real_printf.c
				sed -i '' 's/"_CYAN"//g' .annex/real_printf.c
				sed -i '' 's/"_MAGENTA"//g' .annex/real_printf.c
		   		break;;
		* ) echo "Please answer yes or no, no joke this time";;
	esac
done

echo "Your test is now ready, gl hf"
