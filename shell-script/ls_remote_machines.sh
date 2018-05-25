#!/bin/bash
#从多台远程机器目录上面列出文件

#ip="njjs-ps-201801-m42-feed0035.njjs"
#
#ssh $ip 'ls -l /home/matrix/containers/*normandy*/home/dstream' >> dd.log
#
#
#
#while read -r line
#for line in `cat nj_duli`
#do
#	echo $line >> dd.log
#	ip="$line"
#	echo $ip
#	echo "***---****"
#	ssh $ip 'ls -l /home/matrix/containers/*normandy*/home/dstream' >> dd.log
#	echo "***"
#done


ips="njjs-ps-201801-m42-feed0035.njjs njjs-ps-201801-m42-feed0102.njjs njjs-ps-201801-m42-feed0114.njjs njjs-ps-201801-m42-feed0142.njjs njjs-ps-201801-m42-feed0163.njjs njjs-ps-201801-m42-feed0171.njjs njjs-ps-201801-m42-feed0203.njjs njjs-ps-201801-m42-feed0252.njjs njjs-ps-201801-m42-feed0254.njjs njjs-ps-201801-m42-feed0286.njjs njjs-ps-201801-m42-feed0289.njjs njjs-ps-201801-m42-feed0294.njjs njjs-ps-201801-m42-feed0295.njjs njjs-ps-201801-m42-feed0322.njjs njjs-ps-201801-m42-feed0350.njjs njjs-ps-201801-m42-feed0359.njjs njjs-ps-201801-m42-feed0572.njjs njjs-ps-201801-m42-feed0629.njjs njjs-ps-201801-m42-feed0713.njjs njjs-ps-201801-m42-feed0775.njjs njjs-ps-201801-m42-feed0821.njjs njjs-ps-201801-m42-feed0872.njjs njjs-ps-201801-m42-feed0902.njjs  njjs-ps-201801-m42-feed0912.njjs njjs-ps-201801-m42-feed0941.njjs"

for i in $ips
do 
	echo $i >> dd.log
	ssh $i 'ls -l /home/matrix/containers/*normandy*/home/dstream/AL2_DATA_ANALYZER_DICT/plugin/high_quality_processor/data/author_health_feat.lst' >> dd.log
done

