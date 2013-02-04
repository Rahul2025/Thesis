#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts/Sample

for i in *
{
	echo $i
	cd $i
	for j in *.c
	{
		#compile 'C' program
	/usr/bin/time -f "%e\t%M " gcc $j 
	
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
        /usr/bin/time -f "%e\t%M" ./a.out <ip >c_op
	fi
	#else
	#echo $?
	}
	cd ..
}

for i in *
{
	#echo $i
	cd $i
	for j in *.cpp
	{
		#compile 'CPP' program
	/usr/bin/time -f "%e\t%M " g++ $j 
	
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
        /usr/bin/time -f "%e\t%M" ./a.out <ip >cpp_op
	fi
	#else
	#echo $?
	}
	cd ..
}

for i in *
{
	#echo $i
	cd $i
	for j in *.java
	{
		#compile 'JAVA' program
	/usr/bin/time -f "%e\t%M " javac $j 
	
	#If there were no compilation errors, run the program
	#if [[ $? -eq 0 ]]; then
    #    /usr/bin/time -f "%e\t%M" java <ip >java_op
	#fi
	#else
	#echo $?
	}
	cd ..
}

for i in *
{
	#echo $i
	cd $i
	for j in *.py
	{
		#run 'Python' program
	/usr/bin/time -f "%e\t%M " python $j <ip >py_op
	#else
	#echo $?
	}
	cd ..
}

cd ..
gcc calc_rank.c
./a.out