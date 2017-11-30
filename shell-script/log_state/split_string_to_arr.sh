#!/bin/bash

str=$1

IFS=";"
arr=($str)
for i in ${arr[@]}
do
    echo $i
done

