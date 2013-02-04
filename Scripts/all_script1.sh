#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts/Sample

#<<COMMENT
for i in *.c
{
	#compile 'C' program
	/usr/bin/time -f "%e\t%M " gcc $i 
	
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
        /usr/bin/time -f "%e\t%M" ./a.out >c_op
	fi
	
	echo $i
}

for i in *.cpp
{
	#compile 'C++' program
	/usr/bin/time -f "%e\t%M " g++ $i 
	
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
        /usr/bin/time -f "%e\t%M" ./a.out >cpp_op
	fi
	echo $i
}

for i in *.java
{
	#compile 'JAVA' program
	/usr/bin/time -f "%e\t%M " javac $i 
	
	#If there were no compilation errors, run the program
#	if [[ $? -eq 0 ]]; then
#       /usr/bin/time -f "%e\t%M" java >java_op
#	fi
	echo $i
}

cd ..
gcc calc_rank.c
./a.out