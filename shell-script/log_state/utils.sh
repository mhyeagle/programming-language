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

echo "***"
str="hello\r\nworld\r\nmiao"
echo $str

echo "----------"

for i in `seq 0 10`
do
    echo "****"
    echo $i

    for j in a b
    do
        echo $j
        if [[ $i == 5 ]]
        then 
            break
        fi
    done
done

echo "&&&&&"
a="1"
b="2"
c="3"
echo ${a}${b}"hello"${a}"world"${c}
