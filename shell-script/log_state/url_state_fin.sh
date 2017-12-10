#!/bin/bash

if [[ $# != 3 ]]
then
    echo "paraments error, usage: $0 dir time urls"
    exit 0
fi

dir=$1
time_ori=$2
urls=$3

if [[ $DEBUG == '1' ]]
then
    echo "directory: "$dir
    echo "time_ori: "$time_ori
    echo "urls: "$urls
fi

#format input time
time_dispose() {
    start_time=""

    IFS=" "
    time_ori1=($time_ori)
    IFS=":"
    time_ori1_1=(${time_ori1[1]})
    IFS="-"
    time_ori2=(${time_ori1[0]})

    start_time=${time_ori2[0]}${time_ori2[1]}${time_ori2[2]}${time_ori1_1[0]}
}

#debug
if [[ $DEBUG == 1 ]]
then
    time_dispose
    echo "start_time: "$start_time
    echo "***"
fi

#创建临时文件
tmp_err_file="tmp_err_file"
tmp_filter_file="tmp_filter_file"
cd $dir
if [ -f $tmp_err_file ]
then
    rm $tmp_err_file
fi
if [ -f $tmp_filter_file ]
then
    rm $tmp_filter_file
fi
touch $tmp_err_file
touch $tmp_filter_file

#过滤对应字段到对应的临时文件
filter_file() {
    filter_source=$1

    while read line
    do
        filter_tmp=$(echo $line | grep "ErrorCode")
        if [[ "$filter_tmp" != "" ]]
        then
            echo $line >> $tmp_err_file
        fi

        filter_tmp=$(echo $line | grep "filter\":1")
        if [[ "$filter_tmp" != "" ]]
        then
            echo $line >> $tmp_filter_file
        fi

    done < $filter_source
}

if [[ $DEBUG == 0 ]]
then
    filter_file "rcmc.log.20171123150000"
fi

#遍历日志文件
logfile_hour="rcmc.log"
if [[ -f $logfile_hour ]]
then
    filter_file $logfile_hour
fi
num_hour=0
now_hour=`date +%Y%m%d%H`
log_hour=$now_hour
while [[ $log_hour != $start_time ]]
do
    num_hour=$(($num_hour + 1))
    log_hour=`date --date="$num_hour hour ago" +%Y%m%d%H`
    logfile_hour="rcmc.log."$log_hour"0000"
    echo $logfile_hour
    if [[ -f $logfile_hour ]]
    then
        if [[ $DEBUG == 1 ]]
        then
            echo $logfile_hour
        fi
        filter_file $logfile_hour
    fi
done

#-----------------------
sep_str="\r\n****************\r\n"
errorcode() {
    #$1 url
    while read line
    do
        error_str_line=$(echo $line | grep "$1")
        if [[ $error_str_line != "" ]]
        then
            #url_one=$(echo $1 | awk -F'm_url\":\"' '{print $2}' |awk -F'"' '{print $1}')
            errorcode_one=$(echo $1 | awk -F'ErrorCode' '{print $2}' | awk -F',' '{print $1}' | awk -F':' '{print $2}')
            nid_one=$(echo $1 | awk -F'url_sign\":' '{print $2}' |awk -F'}' '{print $1}')
            result=${result}$1"\r\nnid:"${nid_one}"\r\nerrorcode:"${errorcode_one}
            return 1
        fi
    done < $tmp_err_file

    return 0
}

filter_reason() {
    #$1 url
    while read line
    do
        filter_str_line=$(echo $line | grep "$1")
        if [[ $filter_str_line != "" ]]
        then
            filter_one=$(echo $line | awk -F'filter_reason' '{print $2}' | awk -F'"' '{print $3}')
            nid_one=$(echo $line | awk -F'nid=' '{print $2}' |awk '{print $1}')
            result=${result}${url_one}"\r\nnid:"${nid_one}"\r\nerrorcode:"${filter_one}
            return 1
        fi
    done < $tmp_filter_file

    return 0
}


IFS=";"
urls_arr=($urls)
result=""

for url in ${urls_arr[@]}
do
    result=${result}${sep_str}
    ret=errorcode url
    if [[ ret == 1 ]]
    then
        continue
    fi

    ret=filter url
    if [[ ret == 1 ]]
    then
        continue
    fi

    result=${result}"\r\nsuccess input rcmc"
done

echo $result


