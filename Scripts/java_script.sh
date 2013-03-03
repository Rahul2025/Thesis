#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts/Sample

for folder in *
{
	echo $folder
	cd $folder
	for file in *.java
	{
		echo $file
		#compile 'JAVA' program
		/usr/bin/time -f "%e\t%M " javac $file 
	
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
      /usr/bin/time -f "%e\t%M" java ${file%%.java} <ip >java_op
	fi
	}	
	cd ..
}
