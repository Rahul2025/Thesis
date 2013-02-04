#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc

for i in *
{
	echo $i
	cd $i
	for j in *
	{
		if [[ $j == *.c ]] || [[ $j == *.hs ]] || [[ $j == *.py ]] || [[ $j == *.cpp ]] || [[ $j == *.java ]] || [[ $j == "ip" ]] 
		then
		 	echo $j	
		else
			rm $j
		fi	
	}
	cd ..
}
