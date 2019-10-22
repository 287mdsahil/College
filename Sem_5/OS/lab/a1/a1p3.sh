#!/bin/bash

read -p "Enter the file name: " file
blocks=$( stat --format=%b "$file" )
echo "No of blocks : "$blocks
