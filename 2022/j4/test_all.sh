#!/bin/bash
app1=./j4.py

ls ./TestData | grep '\.in$' | \
while read i; do
	in=./TestData/$i
	out=./TestData/$(echo $i | sed -e 's/in$/out/')
	time ../test.sh $app1 $in $out
done

