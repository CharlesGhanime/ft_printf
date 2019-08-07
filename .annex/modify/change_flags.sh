#!/bin/sh


main_test=.annex/mains_/main_test.c
tmp=.annex/modify/tmp
##														    	##
 #### REMOVE WHAT'S BETWEEN % AND THE CONVERSION INDICATOR	#####
##																##

awk '{gsub(/%[^A-Ga-gm-no-sixXu]+/, "%")} 1' $main_test > $tmp
cat $tmp > $main_test
awk '{gsub(/>[^<]+/, ">")} 1' $main_test > $tmp
cat $tmp > $main_test

##																##
 #### 	INPUT RANDOM FLAG AFTER THE NTH OCCURRENCE OF % 	#####
##																##

i=1
nb_pcent=`grep -o "%" $main_test | wc -l`
a_pct=`grep -o -m$i -E "%.{0,1}" $main_test` 					 
a_pct_c=`grep -o -m$i -E "%.{0,1}" $main_test | cut -c2 | wc -l` ## nb de conv par ligne par match $i + matchs anterieurs
diff=0
diffi=1
perl_conv=1
colors=`grep "_END" $main_test | wc -l | tr -s " " | cut -c 2-`

while [ $diffi -lt $nb_pcent ] 
do
	flag=""
#	diffi=$[$i + $diff]
	a_pct_c=`grep -o -m$i -E "%.{0,1}" $main_test | cut -c2 | wc -l`
	if [ "$a_pct_c" -gt "$diffi" ];then
		j=$[$i+$diff]
		while [ "$j" -le "$a_pct_c" ]
		do
			flag=""
			curr_conv=`grep -oa -m$i -E "%.{0,1}" $main_test | cut -c2 | sed -n ''$j'p'`
			if [[ $curr_conv = [diouxXf] ]];then
				. .annex/modify/random_tools/flag_options.sh
				. .annex/modify/random_tools/width.sh $flag
				. .annex/modify/random_tools/precision.sh $flag
			fi	
			if [[ $curr_conv = [diouxX] ]];then
				. .annex/modify/random_tools/flag_dioux.sh $flag
			elif [[ $curr_conv = 'f' ]];then
				. .annex/modify/random_tools/flag_f.sh $flag
			elif [[ $curr_conv = [csp] ]]; then
				flag=""
				perl_conv=$[ $perl_conv + 1 ]
			fi
			if [[ $colors -ge 1 ]]; then
				perl -pe 's{[;]"_END" [=] %}{++$n == '$perl_conv' ? "\"_END\" >\"_CYAN\"'$flag'\"_END\"<; = %'$flag'" : $&}ge' $main_test > $tmp
			cat $tmp > $main_test
			elif [[ $colors = 0 ]]; then
				perl -pe 's{; [=] %}{++$n == '$perl_conv' ? ">'$flag'<; = %'$flag'" : $&}ge' $main_test > $tmp
				cat $tmp > $main_test
			fi
			diffi=$[$diffi + 1]
			j=$[$j + 1]
		done
	else
		diffi=$[$i+$diff]
		i=$[$i + 1]
		curr_conv=`grep -oa -m$i -E "%.{0,1}" $main_test | cut -c2 | sed -n ''$diffi'p'`
			if [[ $curr_conv = [diouxXf] ]];then
				. .annex/modify/random_tools/flag_options.sh
				. .annex/modify/random_tools/width.sh $flag
				. .annex/modify/random_tools/precision.sh $flag
			fi	
			if [[ $curr_conv = [diouxX] ]];then
				. .annex/modify/random_tools/flag_dioux.sh $flag
			elif [[ $curr_conv = 'f' ]];then
				. .annex/modify/random_tools/flag_f.sh $flag
			elif [[ $curr_conv = [scp] ]];then
				flag=""
				perl_conv=$[ $perl_conv + 1]
			fi
			if [[ $colors -ge 1 ]]; then
				perl -pe 's{"_END"<; [=] %}{++$n == '$perl_conv' ? "\"_END\" >\"_CYAN\"'$flag'\"_END\"<; = %'$flag'" : $&}ge' $main_test > $tmp
			cat $tmp > $main_test
			elif [[ $colors = 0 ]]; then
				perl -pe 's{; [=] %}{++$n == '$perl_conv' ? ">'$flag'<; = %'$flag'" : $&}ge' $main_test > $tmp
				cat $tmp > $main_test
			fi
	fi
done
