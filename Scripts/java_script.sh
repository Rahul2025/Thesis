#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts/Sample


for i in *.java
{
	#compile 'JAVA' program
	/usr/bin/time -f "%e\t%M " javac $i 
	
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
      /usr/bin/time -f "%e\t%M" java >op3
	fi
	echo $i
}
