#!/bin/sh

flag_select=$[ ( RANDOM % $1 ) + 1 ]
export flag_select
