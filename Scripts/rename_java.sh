#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic

for i in *
{
count=0
#echo $i
for j in  $i/*.java
	{
	#echo $j
	if [ $count -eq 0 ]; then
			mv "$j" $i/"Main.java"
			count=1
	else
		mv "$j" $i/"Main_1.java"
	fi
	}
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/GUI

for i in *
{
count=0
#echo $i
for j in  $i/*.java
	{
	#echo $j
	if [ $count -eq 0 ]; then
			mv "$j" $i/"Main.java"
			count=1
	else
		mv "$j" $i/"Main_1.java"
	fi
	}
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/Graph_Algorithms

for i in *
{
count=0
#echo $i
for j in  $i/*.java
	{
	#echo $j
	if [ $count -eq 0 ]; then
			mv "$j" $i/"Main.java"
			count=1
	else
		mv "$j" $i/"Main_1.java"			
			
	fi
	}
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/Numerical_Computing

for i in *
{
count=0
#echo $i
for j in  $i/*.java
	{
	#echo $j
	if [ $count -eq 0 ]; then
			mv "$j" $i/"Main.java"
			count=1
	else
		mv "$j" $i/"Main_1.java"
	fi
	}
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming

for i in *
{
count=0
#echo $i
for j in  $i/*.java
	{
	#echo $j
	if [ $count -eq 0 ]; then
			mv "$j" $i/"Main.java"
			count=1
	else
		mv "$j" $i/"Main_1.java"
	fi
	}
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/NP-Hard

for i in *
{
count=0
#echo $i
for j in  $i/*.java
	{
	#echo $j
	if [ $count -eq 0 ]; then
			mv "$j" $i/"Main.java"
			count=1
	else
		mv "$j" $i/"Main_1.java"
	fi
	}
}