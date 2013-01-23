#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/NP-Hard
rm /home/Rahul/Desktop/Thesis/Scripts/c_cmp
rm /home/Rahul/Desktop/Thesis/Scripts/c_run
rm /home/Rahul/Desktop/Thesis/Scripts/c_time
rm /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
rm /home/Rahul/Desktop/Thesis/Scripts/cpp_run
rm /home/Rahul/Desktop/Thesis/Scripts/cpp_time
rm /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
rm /home/Rahul/Desktop/Thesis/Scripts/hs_run
rm /home/Rahul/Desktop/Thesis/Scripts/hs_time
rm /home/Rahul/Desktop/Thesis/Scripts/java_time
rm /home/Rahul/Desktop/Thesis/Scripts/pyth_time

for i in *
{
	echo $i
	cd $i
	for j in *.c
	{
	if [[ -f $j ]]; then
		#compile 'C' program
		  /usr/bin/time -f "%e\t%M " -o output gcc -lm $j 2>/dev/null 
		  cat output >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
			/usr/bin/time -f "%M" -o output ./a.out <ip >c_op
        cat output >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp
         (time ./a.out <ip >c_op ) 2>op
        cat op >> /home/Rahul/Desktop/Thesis/Scripts/c_run
	fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_cmp 
	fi
	#else
	#echo $?
	}
	cd ..
}


for i in *
{
	#echo $i
	cd $i
	for j in *.cpp
	{
	if [[ -f $j ]]; then
		#compile 'C' program
		   /usr/bin/time -f "%e\t%M " -o output g++ $j 2>/dev/null 
		  cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
			/usr/bin/time -f "%M" -o output ./a.out <ip >cpp_op
        cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
         (time ./a.out <ip >cpp_op ) 2>op
        cat op >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	#else
	#echo $?
	}
	cd ..
}


for i in *
{
	echo $i
	cd $i
	for j in *.hs
	{
	
	if [[ -f $j ]]; then
	rm -r *.o
	rm -r *.hi
	#echo $j.o
		#compile 'Haskell' program
		   /usr/bin/time -f "%e\t%M " -o output  ghc --make -O2 $j -o a.out 2>/dev/null 
		  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
	#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
			/usr/bin/time -f "%M" -o output ./a.out <ip >hs_op
        cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
         (time ./a.out <ip >hs_op ) 2>op
        cat op >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
		fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
	fi
	#else
	#echo $?
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Scripts
bash runtime_script.sh

cd /home/Rahul/Desktop/Thesis/Problem-Set/NP-Hard

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

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
	if [[ -f $j ]]; then
			#compile 'Python' program
		  echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time
		   
		#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
      	 /usr/bin/time -f "%e\t%M" -o output python $j <ip >py_op
       	cat output >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		fi
	#else./a.out $j
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		 
	fi

	#echo $?
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Scripts
gcc make_table_time.c
./a.out >time_np