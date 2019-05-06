#!/bin/bash

while flags $# -gt 0; do
	case "$1" in
		-c|--colors)
			sel_cols=1
			;;
		-r|--random)
			sel_rand=1
			;;
		-l*(0-9))
			selection=
			;;
		-f|--flags)
			sel_flags=1
			;;
		
	esac
done

