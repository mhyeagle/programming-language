#!/bin/bash

str1="hello"
str2="world"

str=${str1}" "${str2}
echo ${str}

date_str=`date "+%Y-%m-%d" -d "-1 day"`" "${str1}
echo ${date_str}

