#!/bin/bash
function pass(){
	if [[ -t 1 ]]; then
		echo -n [32m
		echo "PASS"
		echo -n [0m
	else
		echo "PASS"
	fi
	true
}

function fail(){
	if [[ -t 1 ]]; then
		echo -n [31m
		echo "FAILED"
		echo -n [0m
	else
		echo "FAILED"
	fi
	false
}

# arg1: app to be tested
# arg2: input file name
# arg3: answer file name
function do_test(){
	echo -n "$2 -> $1 -> $3: "
	local output=$(cat "$2" | $1)
	local answer=$(cat "$3")
	if [[ "$output" == "$answer" ]]; then
		pass
	else
		fail
	fi
}

function usage()
{
	echo -e "Usage:\n\ttest.sh app_name in_file out_file"
	exit
}

################# main ###################
if [[ $# -ne 3 ]]; then
	usage
fi

do_test "$@"
