#!/bin/bash

read -p "Enter the file name: " file
read -p "Enter the string to search: " str

numOccur=$(grep -c "$str" $file)

if [ $numOccur -eq 0 ]; then
    echo "string not found"
    exit
fi

echo "number of occurances: $numOccur"
grep -o -n $str $file | cut -d : -f 1 | uniq -c
