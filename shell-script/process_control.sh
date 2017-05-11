#!/bin/bash

#if condition
#then
#    command1
#    command2
#elif condition1
#then
#    command3
#    ...
#else
#    commandN
#fi
#
#for var in item1 item2 item3...
#do
#    command1
#    command2
#    ...
#    commandN
#done
#
#for var in item1 item2 ... itemN; do command1; command2 ... done;


#for var in $(seq 1 10)
#for var in {1..10}
for((var=1;var<=10;var++))
do
    echo $var
done

list="root is me"
for var in $list
do
    echo $var
done
