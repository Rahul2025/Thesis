#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts


tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/c_time > /home/Rahul/Desktop/Thesis/Scripts/temp
mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/c_time

while read line
do
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/c_time > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/c_time
	count=$[count+1]
#	read line
#	if [[ `expr $count % 2` == 0]]; then
#	if [ `expr $count % 2` -eq 0 ]
#	then
#		echo $count
		echo $line 
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/c_time > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/c_time
#	fi
done < /home/Rahul/Desktop/Thesis/Scripts/c_time
