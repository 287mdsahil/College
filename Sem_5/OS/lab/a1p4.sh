#!/bin/bash

read -p "Enter file name 1: " file1
read -p "Enter file name 2: " file2
read -p "Enter file name 3: " file3
read -p "Enter file name 4: " file4

printfCount1=$(grep -c "printf" $file1)
printfCount2=$(grep -c "printf" $file2)
printfCount3=$(grep -c "printf" $file3)
printfCount4=$(grep -c "printf" $file4)

scanfCount1=$(grep -c "scanf" $file1)
scanfCount2=$(grep -c "scanf" $file2)
scanfCount3=$(grep -c "scanf" $file3)
scanfCount4=$(grep -c "scanf" $file4)

intCount1=$(grep -c "int" $file1)
intCount2=$(grep -c "int" $file2)
intCount3=$(grep -c "int" $file3)
intCount4=$(grep -c "int" $file4)

echo -e "File \t\t printf \t scanf \t int"
echo -e "$file1 \t $printfCount1 \t\t $scanfCount1 \t $intCount1"
echo -e "$file2 \t $printfCount2 \t\t $scanfCount2 \t $intCount2"
echo -e "$file3 \t $printfCount3 \t\t $scanfCount3 \t $intCount3"
echo -e "$file4 \t $printfCount4 \t\t $scanfCount4 \t $intCount4"