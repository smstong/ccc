#!/bin/bash
app1=./obj/j2_c

ls ./TestData | grep '\.in$' | \
while read i; do
	in=./TestData/$i
	out=./TestData/$(echo $i | sed -e 's/in$/out/')
	../test.sh $app1 $in $out
done

