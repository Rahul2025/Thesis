#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts/Sample1

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
	if !([[ $j == "setup.py" ]] || [[ $j == "run.py" ]]); then
		if [[ -f $j ]]; then
			echo $j	
		fi	
	fi
	}
	cd ..
}
