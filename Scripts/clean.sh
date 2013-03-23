#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic

for i in *
{
	echo $i
	cd $i
	rm c_op
	for j in *
	{
		
		#echo $j
#		if [[ $j == *_tim.c ]]; 
#			then
#				file=${j%%_tim.c}
				#echo $file
#		elif [[ $j == *_tim.cpp ]];
#			then
#				file=${j%%_tim.cpp}
				#echo $file
#		fi
		
		#echo $file
		#if [ "$j" == "$file" ]
		if [[ $j == *.c ]] || [[ $j == *.hs ]] || [[ $j == *.py ]] || [[ $j == *.pyx ]] || [[ $j == *.cpp ]] || [[ $j == *.java ]] || [[ $j == "ip" ]] || [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
			then
				echo $j	
		else
			rm $j
		fi	
	}
	cd ..
}
#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Graph_Algorithms

for i in *
{
	echo $i
	cd $i
	rm c_op
	for j in *
	{
		
		#echo $j
#		if [[ $j == *_tim.c ]]; 
#			then
#				file=${j%%_tim.c}
				#echo $file
#		elif [[ $j == *_tim.cpp ]];
#			then
#				file=${j%%_tim.cpp}
				#echo $file
#		fi
		
		#echo $file
		#if [ "$j" == "$file" ]
		if [[ $j == *.c ]] || [[ $j == *.hs ]] || [[ $j == *.py ]] || [[ $j == *.pyx ]] || [[ $j == *.cpp ]] || [[ $j == *.java ]] || [[ $j == "ip" ]] || [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
			then
				echo $j	
		else
			rm $j
		fi	
	}
	cd ..
}
#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc

for i in *
{
	echo $i
	cd $i
	rm c_op
	for j in *
	{
		
		#echo $j
#		if [[ $j == *_tim.c ]]; 
#			then
#				file=${j%%_tim.c}
				#echo $file
#		elif [[ $j == *_tim.cpp ]];
#			then
#				file=${j%%_tim.cpp}
				#echo $file
#		fi
		
		#echo $file
		#if [ "$j" == "$file" ]
		if [[ $j == *.c ]] || [[ $j == *.hs ]] || [[ $j == *.py ]] || [[ $j == *.pyx ]] || [[ $j == *.cpp ]] || [[ $j == *.java ]] || [[ $j == "ip" ]] || [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
			then
				echo $j	
		else
			rm $j
		fi	
	}
	cd ..
}
#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/NP-Hard

for i in *
{
	echo $i
	cd $i
	rm c_op
	for j in *
	{
		
		#echo $j
#		if [[ $j == *_tim.c ]]; 
#			then
#				file=${j%%_tim.c}
				#echo $file
#		elif [[ $j == *_tim.cpp ]];
#			then
#				file=${j%%_tim.cpp}
				#echo $file
#		fi
		
		#echo $file
		#if [ "$j" == "$file" ]
		if [[ $j == *.c ]] || [[ $j == *.hs ]] || [[ $j == *.py ]] || [[ $j == *.pyx ]] || [[ $j == *.cpp ]] || [[ $j == *.java ]] || [[ $j == "ip" ]] || [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
			then
				echo $j	
		else
			rm $j
		fi	
	}
	cd ..
}

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Numerical_Computing

for i in *
{
	echo $i
	cd $i
	rm c_op
	for j in *
	{
		
		#echo $j
#		if [[ $j == *_tim.c ]]; 
#			then
#				file=${j%%_tim.c}
				#echo $file
#		elif [[ $j == *_tim.cpp ]];
#			then
#				file=${j%%_tim.cpp}
				#echo $file
#		fi
		
		#echo $file
		#if [ "$j" == "$file" ]
		if [[ $j == *.c ]] || [[ $j == *.hs ]] || [[ $j == *.py ]] || [[ $j == *.pyx ]] || [[ $j == *.cpp ]] || [[ $j == *.java ]] || [[ $j == "ip" ]] || [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
			then
				echo $j	
		else
			rm $j
		fi	
	}
	cd ..
}

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming

for i in *
{
	echo $i
	cd $i
	rm c_op
	for j in *
	{
		
		#echo $j
#		if [[ $j == *_tim.c ]]; 
#			then
#				file=${j%%_tim.c}
				#echo $file
#		elif [[ $j == *_tim.cpp ]];
#			then
#				file=${j%%_tim.cpp}
				#echo $file
#		fi
		
		#echo $file
		#if [ "$j" == "$file" ]
		if [[ $j == *.c ]] || [[ $j == *.hs ]] || [[ $j == *.py ]] || [[ $j == *.pyx ]] || [[ $j == *.cpp ]] || [[ $j == *.java ]] || [[ $j == "ip" ]] || [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
			then
				echo $j	
		else
			rm $j
		fi	
	}
	cd ..
}
