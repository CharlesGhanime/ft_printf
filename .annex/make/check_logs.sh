#!/bin/bash

start=$SECONDS
PID= `ps -aux | grep "sh .annex/make/count_kill.sh" | tail -1 | tr '\t' ' ' | cut -d' ' -f10`

echo "Wanna see the logs?"
read ans
	if [[ $ans == "y" || $ans == "yes" ]]; then
		cat logs
		break
	else
		echo ok; 
		break;
	fi
	if [[ $SECONDS -gt 7 ]]; then
		break;
	fi
`kill SIGTERM $PID`
