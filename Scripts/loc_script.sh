#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts

gcc LOC_final.c

for i in /home/Rahul/Desktop/Thesis/Problem-Set/Graph_Algorithms/*/*.c
{
	./a.out $i 
}
for i in /home/Rahul/Desktop/Thesis/Problem-Set/Graph_Algorithms/*/*.cpp
{
	./a.out $i 
}
for i in /home/Rahul/Desktop/Thesis/Problem-Set/Graph_Algorithms/*/*.java
{
	./a.out $i 
}
for i in /home/Rahul/Desktop/Thesis/Problem-Set/Graph_Algorithms/*/*.py
{
	./a.out $i
}

#gcc calc_LOC.c
#./a.out >loc_graph