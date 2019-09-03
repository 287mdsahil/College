#!/bin/bash

read -p "Enter the file name: " file
read -p "Enter the string to search: " str

numOccur=0
wholematches=0
partialmathches=0

numOccur=$(grep -c "$str" $file)
wholematches=$(grep -wc "$str" $file)
partialmatches=$(($numOccur - $wholematches))

if [ $numOccur -eq 0 ]; then
    echo "string not found"
    exit 0
else
    echo "number of occurances: $numOccur"
    if (($wholematches==0)); then
        echo "number of whole matches: 0"
    else
        echo "number of whole matches: $wholematches"
    fi
    if (($partialmatches==0)); then
        echo "number of partial matches: 0"
    else
        echo "number of partial matches: $partialmatches"
    fi
fi

if (($wholematches!=0)); then
    read -p "Enter the string to replace with: " newstr
    sed -i "s/\b$str\b/$newstr/g" $file
fi
