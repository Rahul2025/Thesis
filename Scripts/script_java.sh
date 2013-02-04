#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic
rm /home/Rahul/Desktop/Thesis/Scripts/java_time

for i in *
{
	echo $i
	cd $i
	for j in *.java
	{
	if [[ -f $j ]]; then
			#compile 'JAVA' program
		  /usr/bin/time -f "%e\t%M " -o output javac $j 2>/dev/null 
		  cat output >> /home/Rahul/Desktop/Thesis/Scripts/java_time
		   
		#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
      	 /usr/bin/time -f "%e\t%M" -o output java ${j%%.java} <ip >java_op
       	cat output >> /home/Rahul/Desktop/Thesis/Scripts/java_time 
		fi
	#else./a.out $j
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/java_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/java_time
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/java_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/java_time 
		  
	fi

	#echo $?
	}
	cd ..
}