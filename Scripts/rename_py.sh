#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo $j
	mv "$j" "q$j"
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/GUI

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo $j
	mv "$j" "q$j"
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/Graph_Algorithms

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo $j
	mv "$j" "q$j"
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/Numerical_Computing

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo $j
	mv "$j" "q$j"
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo $j
	mv "$j" "q$j"
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/NP-Hard

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo $j
	mv "$j" "q$j"
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc

for i in *
{
echo $i
cd $i
for j in *.py
	{
	echo $j
	mv "$j" "q$j"
	}
	cd ..
}