#!/bin/bash

#file=/home/Rahul/Desktop/Thesis
#input directory
cd /home/Rahul/Desktop/Thesis/Scripts
#rm $file/Scripts/all_loc
gcc LOC_final.c

for i in /home/Rahul/Desktop/Thesis/Problem-Set/Numerical_Computing/*
{
#echo $k	
	#echo $i	
	#echo $i
	for j in  $i/*.c
	{
	#echo $j
	if [[ -f $j ]]; then
			./a.out $j
	else 
		echo 0
		echo 0
	fi
	}
	
	for j in  $i/*.cpp
	{
	#echo $j
	if [[ -f $j ]]; then
			./a.out $j
	else 
		echo 0
		echo 0
	fi
	}
	
	for j in  $i/*.hs
	{
	#echo $j
	if [[ -f $j ]]; then
			./a.out $j
	else 
		echo 0
		echo 0
	fi
	}
	
	for j in  $i/*.java
	{
	#echo $j
	if [[ -f $j ]]; then
			./a.out $j
	else 
		echo 0
		echo 0
	fi
	}
	
	for j in  $i/*.py
	{
	#echo $j
	if [[ -f $j ]]; then
			./a.out $j
	else 
		echo 0
		echo 0
	fi
	}
	
	if [ "x$j" == "x" ]; then
		echo 0;
		fi	 
}

gcc make_table_loc.c 
./a.out loc >loc_numerical
#echo -n >loc
#rm loc
#vim loc