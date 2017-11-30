#!/bin/bash

a=0
b=1
c=2

x=$(expr $a + $b)
x=$(($b + $c))
echo $x

x=$(($c - $b))
x=$(($a + 1024))
echo $x

echo "yyyyyy"
y=$(($c * 10))
echo $y

y=$((1024 / $c))
echo $y

echo "***********************"

a="1"
b="2"
x=$(($a + $b))
echo $x

