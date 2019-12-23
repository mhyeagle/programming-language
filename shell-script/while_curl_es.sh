#!/bin/bash

if test $# -ne 1
then
    echo "usage: $0 file"
    exit 1
fi


ids=""
comm1="curl -H \"Content-type:application/json\" -XGET http://es_addrss/index/_search?pretty -d '{\"fields\":[\"user_id\"],\"query\":{\"bool\":{\"must\":[{\"terms\":{\"user_id\":["
comm2="]}}],\"must_not\":[],\"should\":[],\"filter\":{\"terms\":{\"field1\":[\"1\",\"2\"]}}}},\"size\":300}'"
i=0

while read line
do
    if [ $i -ne 300 ]
    then
        ids=$ids\"$line\"","
        let i=($i+1)
        #echo $i
    else
        ids=$ids\"$line\"
        comm=$comm1$ids$comm2
        echo $comm
        # 执行
        eval $comm
        ids=""
        i=0
        sleep 1
    fi
done < $1

