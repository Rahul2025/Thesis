#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc
rm /home/Rahul/Desktop/Thesis/Scripts/pyth_time

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
	echo $j
	if [[ -f $j ]]; then
			#compile 'Python' program
		  echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time
		   
		#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
      	 /usr/bin/time -f "%e\t%M" -o output python $j <ip >py_op
       	cat output >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		fi
	#else./a.out $j
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time
	fi

	#echo $?
	}
	cd ..
}