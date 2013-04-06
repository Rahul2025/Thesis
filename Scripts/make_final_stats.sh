#!/bin/bash

#input directory
#cd /home/Rahul/Desktop/Thesis/Problem-Set/


for i in *
{
	cd $i
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/c_stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/c_stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/c_stats
	echo $line >> stats
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/c_stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/c_stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/c_stats
	echo $line >> stats
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/cpp_stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/cpp_stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/cpp_stats
	echo $line >> stats
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/cpp_stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/cpp_stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/cpp_stats
	echo $line >> stats
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/hs_stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/hs_stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/hs_stats
	echo $line >> stats
	
	read line < /home/Rahul/Desktop/Thesis/Scripts/hs_stats
	tail -n+2 /home/Rahul/Desktop/Thesis/Scripts/hs_stats > /home/Rahul/Desktop/Thesis/Scripts/temp
	mv /home/Rahul/Desktop/Thesis/Scripts/temp /home/Rahul/Desktop/Thesis/Scripts/hs_stats
	echo $line >> stats
	
	cd ..
}