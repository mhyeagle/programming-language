#!/bin/bash

#split string to array
str="abc;def;xyz"

IFS=";"
arr=($str)
for i in ${arr[@]}
do
    echo $i
done

#judge file exist
file="utils.sh"
if [ ! -f $file ]
then
    echo "file not exist"
else
    echo "file exist"
fi

