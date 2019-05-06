#!/bin/bash

sed -i '' "/;/d" .annex/main_test.c
sed -i '' '/^[[:space:]]*$/d' .annex/main_test.c
awk -v n=3 -v s="\n" 'NR == n {print s} {print}' .annex/main_test.c > .annex/tmp
cat .annex/tmp > .annex/main_test.c
perl -0777 -pe 's {\{} {$&\n\treturn (0);}g' .annex/main_test.c > .annex/tmp
cat .annex/tmp > .annex/main_test.c

