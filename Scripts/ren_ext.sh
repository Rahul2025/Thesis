#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/bench

for i in *
{
	echo $i
	cd $i
	for j in *
	{	
		if [[ $j == *.gcc ]]
		then
 			mv "$j" "${j%.gcc}.c"
 			#echo $j
		fi
		
		if [[ $j == *.gpp ]]
		then
 			mv "$j" "${j%.gpp}.cpp"
 			#echo $j
		fi
		
		if [[ $j == *.ghc ]]
		then
 			mv "$j" "${j%.ghc}.hs"
 			#echo $j
		fi
		
		if [[ $j == *.python3 ]]
		then
 			mv "$j" "${j%.python3}.py"
 			#echo $j
		fi
	}
	cd ..
}
