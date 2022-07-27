#!/bin/bash
app1=./obj/j1_c
app2=./obj/j1_cpp

ls ./TestData | grep '\.in$' | \
while read i; do
	in=./TestData/$i
	out=./TestData/$(echo $i | sed -e 's/in$/out/')
	../test.sh $app1 $in $out
done

ls ./TestData | grep '\.in$' | \
while read i; do
	in=./TestData/$i
	out=./TestData/$(echo $i | sed -e 's/in$/out/')
	../test.sh $app2 $in $out
done

