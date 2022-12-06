#!/bin/bash
ls TestData/*.data |
while read f_in
do
    f_out=$(echo $f_in | sed -e 's/data$/out/')
    output=$(cat $f_in | ./j5)
    answer=$(cat $f_out)

    echo -n "$f_in => $f_out: "
    if [[ "${output}" = "${answer}" ]]; then
        echo "PASS"
    else
        echo "FAIL"
    fi
done

