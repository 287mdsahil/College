#!/bin/bash

read -p "Enter the file name: " file
read -p "Enter the string to search: " str

numOccur=$(grep -c "$str" $file)

if [ $numOccur -eq 0 ]; then
    echo "string not found"
    exit
fi

echo "number of occurances: $numOccur"
echo -e "\nLine\tfreq"
grep -o -n $str $file | cut -d : -f 1 | uniq -c |
while read -r line ; do
    token=($line)
    printf "%-8d%d\n" ${token[1]} ${token[0]}
done
