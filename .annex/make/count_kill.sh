#!/bin/bash

while [ $SECONDS -lt 7 ]; do
	`sleep 1`
done

PID=`ps aux | grep "sh .annex/make/check_logs.sh" | tail -1 | tr '\t' ' ' | cut -d' ' -f10`
echo $PID
`kill SIGTERM $PID`
