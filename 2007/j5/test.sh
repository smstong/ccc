#!/bin/bash
ls TestData/*.in |
while read f_in
do
    f_out=$(echo $f_in | sed -e 's/in$/exp/')
    output=$(cat $f_in | ./j5)
    answer=$(cat $f_out)

    echo -n "$f_in => $f_out: "
    if [[ $answer == $output ]]; then
        echo "PASS"
    else
        echo "FAIL"
    fi
done

