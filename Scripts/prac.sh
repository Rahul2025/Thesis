#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts

for ja in Sample1/S3
{
c=0
cpp=0
p=0
j=0
h=0
for i in *
{	
	if [[ $i == *.c ]]; then
			c=1
	fi	
	 
	if [[ $i == *.cpp ]]; then
			cpp=1 
	fi	 
	
	if [[ $i == *.java ]]; then
			j=1 
	fi	 
	
	if [[ $i == *.py ]]; then
			p=1 
	fi	 
}
echo $c $cpp $j $p
}