#!/bin/bash

start_hour="2017113018"

num_hour=0

now=`date +%Y%m%d%H`
echo "now:" $now

log_hour=$now
while [[ $log_hour != $start_hour ]]
do
    echo $log_hour
    num_hour=$(($num_hour + 1))
    echo $num_hour

    log_hour=`date --date="$num_hour hour ago" +%Y%m%d%H`
done
echo $log_hour

echo "******************"
while [[ $num_hour != 0 ]]
do
    log_hour=`date --date="$num_hour hour ago" +%Y%m%d%H`
    echo $log_hour
    num_hour=$(($num_hour - 1))
done

