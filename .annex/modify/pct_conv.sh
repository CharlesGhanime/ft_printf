#!/bin/bash

#
### CLEANING
#
	. .annex/modify/cleaning/clean.sh
#
### SETTING UP
#
	. .annex/modify/options/options.sh
	. .annex/modify/prompt/line_nb.sh $selection
	. .annex/modify/prompt/conv_choice.sh $selection
#
### INPUTTING
#

main_test=.annex/mains_/main_test.c
tmp=.annex/tmp

i=0
add_var=""
m_var=""
while [[ "$i" -lt "$line_nb" ]]
do
	j=0
	input_pf=""
	var_name=""
	if [[ $1 ]]; then
		pct_nb=$1
	elif [[ $selection == 1 ]]; then
		pct_nb=4
	elif [[ $selection == 2 ]]; then
		pct_nb=10
	elif ! [[ $selection ]]; then
		pct_nb=$[ ( RANDOM % 4 ) + 1]
	fi
	while [ "$j" -lt "$pct_nb" ]
	do
		var_index="$i$j"
		. .annex/modify/random_tools/conv_select.sh "$choice"
		. .annex/modify/random_tools/variables.sh "${conv}"
		if [[ $conv == 's' ]];then
			m_var=`echo $var | cut -c 2- | rev | cut -c 3- | rev`
			input_pf+="$conv $m_var = %$conv"
		else
			input_pf+="\"_BBLUE\"$conv\"_END\" \"_MAGENTA\"$var\"_END\" = %$conv"	
		fi
		. .annex/modify/random_tools/designation.sh "${conv}" "${var_index}"
		add_var=([0]=""${designation[0]}" = "${var[0]}"")
		perl -0777 -pe "s {\)\n\{} {$&\n\t${add_var[0]}}g" $main_test > $tmp
		cat $tmp > $main_test
		. .annex/modify/random_tools/var_name.sh $conv $var_index
		var_name+="$chosen_name,"
		j=$[$j + 1]
	done
	var_name=`echo $var_name | sed 's/.$//'`
	if [ $i -lt 1 ];then
		awk '/return/{c++;if(c==1){printf "\n"; c=0}} 1' $main_test > $tmp
		cat $tmp > $main_test
	fi
	awk -v input="$input_pf" -v name="$var_name" '
	/return/ {
	c++
	if(c==1) {
		printf "\tprintf(\"%s\", %s);\n", input, name
		c=1
	}
}
1 { print }' $main_test > $tmp
cat $tmp > $main_test
i=$[$i + 1]
done

sed -i '' 's/%[diouxXfpcs]/&\\n/g' $main_test

#
## FLAGS AND COLORS
#
	. .annex/modify/prompt/flags_or_not.sh $selection
	. .annex/modify/prompt/colors.sh $selection

rm $tmp
echo "Your test is now ready, gl hf"
