#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts
rm /home/Rahul/Desktop/Thesis/Scripts/c_stats
rm /home/Rahul/Desktop/Thesis/Scripts/cpp_stats
rm /home/Rahul/Desktop/Thesis/Scripts/hs_stats

count=0
while read line
do
	count=$[count+1]
#	if [[ `expr $count % 2` == 0]]; then
	if [ `expr $count % 2` -eq 0 ]
	then
		echo $count
		echo $line >> c_stats
	fi
done < c_time

count=0
while read line
do
	count=$[count+1]
#	if [[ `expr $count % 2` == 0]]; then
	if [ `expr $count % 2` -eq 0 ]
	then
		echo $count
		echo $line >> cpp_stats
	fi
done < cpp_time

count=0
while read line
do
	count=$[count+1]
#	if [[ `expr $count % 2` == 0]]; then
	if [ `expr $count % 2` -eq 0 ]
	then
		echo $count
		echo $line >> hs_stats
	fi
done < hs_time