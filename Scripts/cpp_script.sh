#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic
rm /home/Rahul/Desktop/Thesis/Scripts/cpp_time
rm /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
rm /home/Rahul/Desktop/Thesis/Scripts/cpp_run

for i in *
{
	#echo $i
	cd $i
	for j in *.cpp
	{
	if [[ -f $j ]]; then
		#compile 'C' program
		   /usr/bin/time -f "%e\t%M " -o output g++ $j 2>/dev/null 
		  cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
			/usr/bin/time -f "%M" -o output ./a.out <ip >cpp_op
        cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
         (time ./a.out <ip >cpp_op ) 2>op
        cat op >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	#else
	#echo $?
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Scripts
bash cpp_runtime_script.sh