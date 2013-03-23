#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming

for folder in *
{
	echo $folder
	cd $folder
	for file in *.java
	{
		echo $file
		if [[ -f $file ]]; then
			#compile 'JAVA' program
			/usr/bin/time -f "%e\t%M " javac $file 
	
			#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
				if [[ $folder == "MIME2" ]]; then
					/usr/bin/time -f "%e\t%M" java ${file%%.java} <ip >java_op
				else
					/usr/bin/time -f "%e\t%M" java ${file%%.java} >java_op
				fi
			fi
		else
			echo 0 0
			echo 0 0
		fi
	}	
	cd ..
}
