#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts/Sample1

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
	if [[ -f $j ]]; then
		if !([[ $j == "setup.py" ]] || [[ $j == "run.py" ]]); then
		   echo $j
			if [[ $? -eq 0 ]]; then
				src=$j
				targt=$j"x"
#				echo $targt
				# copy file 
				cp $src $targt
				status=$?	# store exit status of above cp command. It is use to determine  if shell command operations is successful or not
				if !([[ $status -eq 0 ]]); then
					echo 'Problem copying file...'
				fi	 
			fi
		fi
	fi
	#echo $?
	}
	cd ..
}
