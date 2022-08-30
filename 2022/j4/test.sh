#!/bin/bash
ls TestData/*.in |
while read i
do
	f_in=$i
	f_out=$(echo $i | sed -e 's/in$/out/')
	output=$(cat $f_in | ./j4.py)
	answer=$(cat $f_out)

	echo -n "$f_in: "
	if [[ "$output" == "$answer" ]]; then
		echo "PASS"
	else
		echo "FAIL"
	fi
done
