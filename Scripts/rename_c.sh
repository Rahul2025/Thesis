#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo q$j
	}
	cd ..
}