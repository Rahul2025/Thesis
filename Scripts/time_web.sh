#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Web-Programming
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
rm /home/Rahul/Desktop/Thesis/Scripts/cyth_time

for i in *
{
	echo $i
	cd $i
	rm stats
	rm run.py
	rm setup.py
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
	echo $j
		#compile 'Haskell' program
		ghc $j
		
	#  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
	#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
				if [[ $i == "MIME2" ]]; then
					/usr/bin/time -f "%e\t%M" ./a.out <ip >c_op
				else
					/usr/bin/time -f "%e\t%M" ./a.out >c_op
				fi
      # cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
      #   (time ./a.out <ip >hs_op ) 2>op
      #  cat op >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
		fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
	fi
	#else
	#echo $?
	#fi
	}
	cd ..
}


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

for i in *
{
	echo $i
	cd $i
	for j in *.hs
	{
	
	if [[ -f $j ]]; then
	rm -r *.o
	rm -r *.hi
	echo $j
		#compile 'Haskell' program
		ghc $j
		
	#  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
	#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
				if [[ $i == "MIME2" ]]; then
					/usr/bin/time -f "%e\t%M" ./a.out <ip >c_op
				else
					/usr/bin/time -f "%e\t%M" ./a.out >c_op
				fi
      # cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
      #   (time ./a.out <ip >hs_op ) 2>op
      #  cat op >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
		fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
	fi
	#else
	#echo $?
	#fi
	}
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Scripts
bash runtime_script.sh
bash make_stats.sh

cd /home/Rahul/Desktop/Thesis/Problem-Set/NP-Hard
bash /home/Rahul/Desktop/Thesis/Scripts/make_final_stats.sh
for folder in *
{
	echo $folder
	cd $folder
	for file in *.java
	{
		echo $file
		if [[ -f $file ]]; then
			#compile 'JAVA' program
			/usr/bin/time -f "%e\t%M " javac $file 
	
			#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
				if [[ $folder == "MIME2" ]]; then
					/usr/bin/time -f "%e\t%M" java ${file%%.java} <ip >java_op
				else
					/usr/bin/time -f "%e\t%M" java ${file%%.java} >java_op
				fi
			fi
		else
			echo 0 0
			echo 0 0
		fi
	}	
	cd ..
}

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
		echo $j
		#interpret 'Python' program
		if [[ -f $j ]]; then
			if [[ $i == "MIME2" ]]; then
				/usr/bin/time -f "%e\t%M " python $j <ip >pyth_op
			elif [[ $i == "HTTP" ]] || [[ $i == "HTTPS" ]]; then
				/usr/bin/time -f "%e\t%M " python3 $j >pyth_op
			else
				/usr/bin/time -f "%e\t%M " python $j >pyth_op
			fi
		fi	
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
		if !([[ $j == "setup.py" ]] || [[ $j == "run.py" ]] ); then
			#compile 'Cython' program
			echo $j
		 	echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cyth_time
		 	if [[ $j == "qq58_tim.py" ]] || [[ $j == "qq15_mem.py" ]] || [[ $j == "qq15_tim.py" ]]; then
				echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cyth_time
			#If there were no compilation errors, run the program
			else
					src=$j
					targt=$j"x"
					# copy file 
					cp $src $targt
					status=$?	# store exit status of above cp command. It is use to determine  if shell command operations is successful or not
					if !([[ $status -eq 0 ]]); then
						echo 'Problem copying file...'
					fi
					file=${j%%.py}
					gcc /home/Rahul/Desktop/Thesis/Scripts/make_setup.c 
					./a.out $file
					python setup.py build_ext --inplace
					gcc /home/Rahul/Desktop/Thesis/Scripts/make_run.c 
					./a.out $file
					/usr/bin/time -f "%M" -o output python run.py <ip >cy_op
					cat output >> /home/Rahul/Desktop/Thesis/Scripts/cyth_time 
			fi
		fi
	#else./a.out $j
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cyth_time 
		 
	fi
	#echo $?
	}
	
	
	cd ..
}

for i in *
{
	echo $i
	
	cd $i
#	rm temp
	g++ /home/Rahul/Desktop/Thesis/Scripts/make_csv.cpp
	./a.out
	
#	rm stats
	mv temp stats
#	rm temp
	for j in *
	{
			if   [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
				then
	#				echo $j
					id=${j#"q"}
		#			echo $id","
				fi
				
#			if [[ $j == "stats" ]]
			
	}
	echo $id","| cat - stats > temp 
#	mv temp stats
	sed 's/\(.*\)./\1/' temp >stats
	rm temp
	
	cd ..
}

cd /home/Rahul/Desktop/Thesis/Scripts
gcc make_table_time.c
./a.out >time_web