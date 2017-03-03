#!/bin/bash

sum=0
while read line
do
    sum=`expr $sum + $line`
done < lines
echo $sum
