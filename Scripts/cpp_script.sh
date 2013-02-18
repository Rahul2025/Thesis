#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc
#rm /home/Rahul/Desktop/Thesis/Scripts/cpp_time
#rm /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
#rm /home/Rahul/Desktop/Thesis/Scripts/cpp_run

for i in *
{
	
	echo $i
	
	cd $i
	for j in *.cpp
	{
	#echo $j
	if [[ -f $j ]]; then
		#compile 'Cpp' program
		
		if [[ $i == "thread-ring" ]]; 
			then
 				/usr/bin/time -f "%e\t%M " /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native $j -o $j.o && /usr/bin/g++ $j.o -o a.out -lpthread 2>/dev/null
		elif [[ $i == "spectral-norm" ]] || [[ $i == "reverse-complement" ]]; 
			then
				/usr/bin/time -f "%e\t%M " /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native -mfpmath=sse -msse2 -fopenmp -O0 $j -o $j.o && /usr/bin/g++ $j.o -o a.out -fopenmp
		elif [[ $i == "fannkuch-redux" ]] || [[ $i == "k-nucleotide" ]];
			then
				/usr/bin/time -f "%e\t%M " /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native  -std=c++0x $j -o $j.o && /usr/bin/g++ $j.o -o a.out -lpthread
		else
			/usr/bin/time -f "%e\t%M "  /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native -mfpmath=sse -msse3 --std=c++0x $j -o $j.o && /usr/bin/g++ $j.o -o a.out
		fi		
		#    g++ $j 2>/dev/null 
	#	  cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
			/usr/bin/time -f "%e\t%M" ./a.out <ip >cpp_op
   #     cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
   #      (time ./a.out <ip >cpp_op ) 2>op
    #    cat op >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	#else
	#echo $?
	echo "-------------------"
	}
	cd ..
}

#cd /home/Rahul/Desktop/Thesis/Scripts
#bash cpp_runtime_script.sh