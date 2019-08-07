#!/bin/bash

main_test=.annex/mains_/main_test.c

sed -i '' "/;/d" $main_test
sed -i '' '/^[[:space:]]*$/d' $main_test
awk -v n=3 -v s="\n" 'NR == n {print s} {print}' $main_test > .annex/tmp
cat .annex/tmp > $main_test
perl -0777 -pe 's {\{} {$&\n\treturn (0);}g' $main_test > .annex/tmp
cat .annex/tmp > $main_test

