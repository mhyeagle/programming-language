#!/bin/bash

declare -A map=()

declare -A map1=(["100"]="1" ["200"]="2")

#输出所有key
echo ${!map[@]}

#输出所有的value
echo ${map[@]}

#添加值
map["300"]="3"

#输出key对应的值
echo ${map["100"]}

value=${map["100"]}
if [[ $value == "" ]]
then
    echo "value is empty"
fi

#遍历map
for key in ${!map[@]}
do
    echo ${map[$key]}
done

