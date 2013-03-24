#!/bin/bash

#input directory
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
echo $i
cd $i

count=0
while [ `expr $count ` == 0 ]
do
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/c_time > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/c_time
	count=$[count+1]
	read line
#	if [[ `expr $count % 2` == 0]]; then
#	if [ `expr $count % 2` -eq 0 ]
#	then
#		echo $count
		echo $line >> /home/Rahul/Desktop/Thesis/Problem-Set/Basic/$i/stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/c_time > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/c_time
#	fi
done < /home/Rahul/Desktop/Thesis/Scripts/c_time
cd ..
}