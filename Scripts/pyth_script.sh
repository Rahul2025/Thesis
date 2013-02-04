#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
		if [[ -f $j ]]; then
			echo $j
			#interpret 'Python' program
			/usr/bin/time -f "%e\t%M " python $j <ip
		fi	
	}
	cd ..
}