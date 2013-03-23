#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming

for i in *
{
	echo $i
	cd $i
	for j in *.hs
	{
	
	if [[ -f $j ]]; then
	rm -r *.o
	rm -r *.hi
	echo $j
		#compile 'Haskell' program
		ghc $j
		
	#  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
	#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
				if [[ $i == "MIME2" ]]; then
					/usr/bin/time -f "%e\t%M" ./a.out <ip >c_op
				else
					/usr/bin/time -f "%e\t%M" ./a.out >c_op
				fi
      # cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
      #   (time ./a.out <ip >hs_op ) 2>op
      #  cat op >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
		fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
	fi
	#else
	#echo $?
	#fi
	}
	cd ..
}

#cd /home/Rahul/Desktop/Thesis/Scripts
#bash hs_runtime_script.sh