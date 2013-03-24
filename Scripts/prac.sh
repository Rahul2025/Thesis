#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts
rm /home/Rahul/Desktop/Thesis/Scripts/stats

count=0
while read line
do
	count=$[count+1]
#	if [[ `expr $count % 2` == 0]]; then
	if [ `expr $count % 2` -eq 0 ]
	then
		echo $count
		echo $line >> stats
	fi
done < c_time


cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic

for i in *
{
	echo $i
	cd $i
	rm stats
	cd ..
}

for i in *
{
	cd $i
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/stats
	echo $line >> /home/Rahul/Desktop/Thesis/Problem-Set/Basic/$i/stats
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/stats
	echo $line >> /home/Rahul/Desktop/Thesis/Problem-Set/Basic/$i/stats
	
	cd ..
}