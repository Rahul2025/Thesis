#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Scripts/Sample1

for i in *
{
count=0
#echo $i
for j in  $i/*.java
	{
	#echo $j
	if [ $count -eq 0 ]; then
			mv "$j" $i/"Main.java"
			count=1
	else
		mv "$j" $i/"Main_1.java"
	fi
	}
}