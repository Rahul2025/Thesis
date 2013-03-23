#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
		echo $j
		#interpret 'Python' program
		if [[ -f $j ]]; then
			if [[ $i == "MIME2" ]]; then
				/usr/bin/time -f "%e\t%M " python $j <ip >pyth_op
			elif [[ $i == "HTTP" ]] || [[ $i == "HTTPS" ]] || [[ $i == "HTTPS_Authenticated" ]]; then
				/usr/bin/time -f "%e\t%M " python3 $j >pyth_op
			else
				/usr/bin/time -f "%e\t%M " python $j >pyth_op
			fi
		fi	
	}
	cd ..
}