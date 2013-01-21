#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc
#rm /home/Rahul/Desktop/Thesis/Scripts/c_time
#rm /home/Rahul/Desktop/Thesis/Scripts/c_cmp
#rm /home/Rahul/Desktop/Thesis/Scripts/c_run

for i in *
{
	#echo $i
	cd $i
	for j in *.c
	{
	#if [ "x$j" == "x*.c" ]; then
	#	echo 0;
	#else	 
	#	make /usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -mfpmath=sse -msse3 $j -lm
		
	#fi
	if [[ -f $j ]]; then
		#compile 'C' program
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -mfpmath=sse -msse3 $j -o a.out -lm -lgmp

		 fi #cat output >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp
	#If there were no compilation errors, run the program
	#if [[ $? -eq 0 ]]; then
		#	/usr/bin/time -f "%M" -o output ./a.out <ip >c_op
       # cat output >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp
        # (time ./a.out <ip >c_op ) 2>op
        #cat op >> /home/Rahul/Desktop/Thesis/Scripts/c_run
#	fi
#	else 
#		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp 
#		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/c_run
#	fi
	#else
	#echo $?
	}
	cd ..
}

#cd /home/Rahul/Desktop/Thesis/Scripts
#bash c_runtime_script.sh