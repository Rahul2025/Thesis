#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic
rm /home/Rahul/Desktop/Thesis/Scripts/hs_time
rm /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
rm /home/Rahul/Desktop/Thesis/Scripts/hs_run

for i in *
{
	echo $i
	cd $i
	for j in *.hs
	{
	
	if [[ -f $j ]]; then
	rm -r *.o
	rm -r *.hi
	#echo $j.o
		#compile 'Haskell' program
		   /usr/bin/time -f "%e\t%M " -o output  ghc --make -O2 $j -o a.out 2>/dev/null 
		  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
	#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
			/usr/bin/time -f "%M" -o output ./a.out <ip >hs_op
        cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
         (time ./a.out <ip >hs_op ) 2>op
        cat op >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
		fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
	fi
	#else
	#echo $?
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Scripts
bash hs_runtime_script.sh