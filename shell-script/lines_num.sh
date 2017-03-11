#!/bin/bash

if test $# -ne 1
then
    echo "usage: $0 file"
    exit 1
fi

sum=0
while read line
do
    sum=`expr $sum + $line`
done < $1
echo $sum
