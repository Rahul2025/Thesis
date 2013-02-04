#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Scripts
gcc LOC_total.c

for i in /home/Rahul/Desktop/Thesis/Problem-Set/Basic/*/*.hs
{
	#echo $i
	#for j in $i/*.hs
	#{
	#	if [ -f $i/*.hs ]; then
			./a.out $i
			./a.out 
	#	fi 
	#}
}