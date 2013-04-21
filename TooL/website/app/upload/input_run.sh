#!/bin/bash

cd upload
#rm output
input_path=$1
output_path="stats"

#First , ask user, if he provides with the compile and/or run commands for his program.....

#If not, then run the following script

for file in *
{
	echo $file
	
	if [[ $file == *.c ]]; then 
		echo "C Program..."
		#compile 'C' program
			gcc -lm $file 2>/dev/null 
		#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
				/usr/bin/time -f "%e\n%M" -o op ./a.out < $input_path >output 
        			cat op >> $output_path
        	fi
        
	elif [[ $file == *.cpp ]]; then 
		echo "C++ Program..."
		#compile 'CPP' program
		   g++ $file 2>/dev/null 
		#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
				/usr/bin/time -f "%e\n%M" -o op ./a.out < $input_path >output
        			cat op >> $output_path
         	#(time ./a.out < $input_path >cpp_op ) 2>op
        		#	cat op >> c_run
      
			fi
	
	
	elif [[ $file == *.hs ]]; then 
		echo "Haskell Program..."
		#compile 'Haskell' program
		   ghc --make -O2 $file -o a.out 2>/dev/null 
		#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
				/usr/bin/time -f "%e\n%M" -o op ./a.out < $input_path >output
        			cat op >> $output_path
         	#(time ./a.out < $input_path >hs_op ) 2>op
        		#	cat op >> $output_path
			fi
	
	elif [[ $file == *.java ]]; then 
		echo "Java Program..."
		#compile 'JAVA' program
			javac $file 2>/dev/null    
		#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
      		/usr/bin/time -f "%e\n%M" -o op java ${j%%.java} < $input_path >output
        			cat op >> $output_path
			fi
	
	elif [[ $file == *.py ]]; then 
		echo "Pyhton Program..."
		#Run 'Python' Program
		if [[ $? -eq 0 ]]; then
      		/usr/bin/time -f "%e\n%M" -o op python $file < $input_path >output
        			cat op >> $output_path
		fi
	
	else
		echo "Unknown file format - NOT supported"
	fi
}


#Now check the 'output' file with saved ouput in each folder....

#if matched, then compare stats...and replace or discard the file accordingly...