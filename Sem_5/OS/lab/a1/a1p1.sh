#!/bin/bash

while true; do
    # Taking inputs
    read -p 'Enter the first variable : ' var1
    read -p 'Enter the second variable : ' var2

    result=$(echo "scale=2;$var1 + $var2" | bc) 
    echo "$var1 + $var2 = " $result

    result=$(echo "scale=2;$var1 - $var2" | bc) 
    echo "$var1 - $var2 = " $result

    result=$(echo "scale=2;$var1 * $var2" | bc) 
    echo "$var1 * $var2 = " $result

    result=$(echo "scale=2;$var1 / $var2" | bc) 
    echo "$var1 / $var2 = " $result

    # Exit check
    read -p 'Continue (y/n) : ' loopvar
    if [ "$loopvar" == "y" ] ; then
        echo
        continue
    else
        exit 1
    fi
done
