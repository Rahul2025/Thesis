#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming

for i in *
{
	echo $i
	cd $i
	for j in *.cpp
	{
	if [[ -f $j ]]; then
	
 			echo $j	
 			#compile 'CPP' program
 			if [[ $j == "Web_Scraping" ]]; then
 				/usr/bin/time -f "%e\t%M " g++ -lboost_regex -lboost_system -lboost_thread $j
 			else
 				/usr/bin/time -f "%e\t%M " g++ -lcurl $j
 			fi
 				
		 #cat output >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
		if [[ $i == "MIME2" ]]; then
					/usr/bin/time -f "%e\t%M" ./a.out <ip >java_op
				else
					/usr/bin/time -f "%e\t%M" ./a.out >java_op
       # cat op >> /home/Rahul/Desktop/Thesis/Scripts/c_run
       fi
	fi
	else 
		echo 0 0 #>> /home/Rahul/Desktop/Thesis/Scripts/c_cmp 
		echo 0 #>> /home/Rahul/Desktop/Thesis/Scripts/c_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/c_run
	fi
	#else
	#echo $?
	}
	cd ..
}

#cd /home/Rahul/Desktop/Thesis/Scripts
#bash c_runtime_script.sh