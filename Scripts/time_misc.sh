#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc
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
	for j in *.c
	{
	if [[ -f $j ]]; then
	 #echo $j	
 			#compile 'C' program
 			if [[ $i == "thread-ring" ]] || [[ $i == "fannkuch-redux" ]]; then
 				 /usr/bin/time -f "%e\t%M " -o output /usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -pthread -falign-labels=8 $j -o a.out 2>/dev/null
			elif [[ $i == "pidigits" ]]; then
			 	 /usr/bin/time -f "%e\t%M " -o output /usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native $j -o a.out -lgmp 2>/dev/null
 			else	
 				/usr/bin/time -f "%e\t%M " -o output /usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -pthread -falign-labels=8 -Os -fopenmp -mfpmath=sse -msse2 -std=c99 -lm $j -o a.out 2>/dev/null		
 			#/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -pthread -falign-labels=8 $j
	fi	
		 #fi 
		 cat output >> /home/Rahul/Desktop/Thesis/Scripts/c_time
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
		#	 -o output 
					/usr/bin/time -f "%e\t%M" -o output ./a.out <ip >c_op
        cat output >> /home/Rahul/Desktop/Thesis/Scripts/c_time
        cat output >> stats
       #  (time ./a.out <ip >c_op ) 2>op
      #  cat op >> /home/Rahul/Desktop/Thesis/Scripts/c_run
	fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_time
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_time 
		echo 0 0 >> stats
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/c_time
		echo 0 0 >> stats
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/c_run
	fi
	#else
	#echo $?
	}
	cd ..
}

sleep 600

for i in *
{
	
	echo $i
	
	cd $i
	for j in *.cpp
	{
	
	if [[ -f $j ]]; then
		#compile 'CPP' program
		echo $j
		if [[ $i == "thread-ring" ]]; 
			then
 				/usr/bin/time -f "%e\t%M " -o output /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native $j -o $j.o && /usr/bin/g++ $j.o -o a.out -lpthread 2>/dev/null
		elif [[ $i == "spectral-norm" ]] || [[ $i == "reverse-complement" ]]; 
			then
				/usr/bin/time -f "%e\t%M " -o output /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native -mfpmath=sse -msse2 -fopenmp -O0 $j -o $j.o && /usr/bin/g++ $j.o -o a.out -fopenmp 2>/dev/null
		elif [[ $i == "fannkuch-redux" ]] || [[ $i == "k-nucleotide" ]];
			then
				/usr/bin/time -f "%e\t%M " -o output /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native  -std=c++0x $j -o $j.o && /usr/bin/g++ $j.o -o a.out -lpthread 2>/dev/null
		else
				/usr/bin/time -f "%e\t%M " -o output /usr/bin/g++ -c -pipe -O3 -fomit-frame-pointer -march=native -mfpmath=sse -msse3 --std=c++0x $j -o $j.o && /usr/bin/g++ $j.o -o a.out 2>/dev/null
		fi		
		#    g++ $j 2>/dev/null 
		  cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_time
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
			 /usr/bin/time -f "%e\t%M" -o output ./a.out <ip >cpp_op
        cat output >> /home/Rahul/Desktop/Thesis/Scripts/cpp_time
        cat output >> stats
   #      (time ./a.out <ip >cpp_op ) 2>op
    #    cat op >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_time
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_time 
		echo 0 0 >> stats
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/cpp_time
		echo 0 0 >> stats
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/cpp_run
	fi
	#else
	#echo $?
	#echo "-------------------"
	}
	cd ..
}

sleep 600

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
		if   [[ $i == "binary-trees-redux" ]] || [[ $i == "fannkuch-redux" ]] || [[ $i == "fasta" ]] || [[ $j == "q139_tim.hs" ]] || [[ $i == "k-nucleotide" ]] || [[ $i == "meteor-contest" ]] || [[ $i == "n-body" ]] || [[ $i == "pidigits" ]] || [[ $i == "thread-ring" ]]; 
			then
		   	/usr/bin/time -f "%e\t%M " -o output ghc --make -O2 -XBangPatterns -threaded $j -o a.out 2>/dev/null 		
		elif [[ $i == "thread-ring" ]];
			then
				/usr/bin/time -f "%e\t%M " -o output ghc --make -O2 -fglasgow-exts -threaded $j -o a.out 2>/dev/null
		elif [[ $i == "binary-trees" ]];
			then
				/usr/bin/time -f "%e\t%M " -o output ghc --make -O2 -XBangPatterns -threaded -funbox-strict-fields $j -o a.out 2>/dev/null
		elif [[ $i == "chameneos-redux" ]]; 
			then
				/usr/bin/time -f "%e\t%M " -o output ghc --make -O2 -XBangPatterns -threaded -XCPP -XGeneralizedNewtypeDeriving $j -o a.out 2>/dev/null
		elif [[ $i == "spectral-norm" ]];
			then
				/usr/bin/time -f "%e\t%M " -o output ghc --make -O2 -XBangPatterns -threaded -XMagicHash -fexcess-precision $j -o a.out 2>/dev/null
		else
				/usr/bin/time -f "%e\t%M " -o output ghc --make -O2 -XBangPatterns -threaded -funfolding-use-threshold=32 -XMagicHash -XUnboxedTuples -fexcess-precision $j -o a.out 2>/dev/null
			# -o output  ghc --make -O2 -XBangPatterns -threaded -XMagicHash  $j
			# -o output  ghc --make -O2 -XBangPatterns -fexcess-precision $j	
		fi	
	  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_time
	#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
			if [[ $i == "binary-trees" ]]; then
				/usr/bin/time -f "%e\t%M" -o output ./a.out +RTS -N4 -K128M -H -RTS <ip >hs_op
				cat output >> stats
			else
				/usr/bin/time -f "%e\t%M" -o output ./a.out +RTS -N4 -RTS <ip >hs_op
				cat output >> stats
       
      	fi
       cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_time
       #  (time ./a.out <ip >hs_op ) 2>op
      #  cat op >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
		fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_time
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_time 
		echo 0 0 >> stats
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_time
		echo 0 0 >> stats
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
	fi
	#else
	#echo $?
	#fi
	}
	cd ..
}


#cd /home/Rahul/Desktop/Thesis/Scripts
#bash runtime_script.sh

#cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc
sleep 600
for folder in *
{
	echo $folder
	cd $folder
	for file in *.java
	{
		echo $file
		#compile 'JAVA' program
		/usr/bin/time -f "%e\t%M " -o output javac $file 
		cat output >> /home/Rahul/Desktop/Thesis/Scripts/java_time
	
	#If there were no compilation errors, run the program
	if [[ $? -eq 0 ]]; then
      /usr/bin/time -f "%e\t%M " -o output java ${file%%.java} <ip >java_op
      cat output >> /home/Rahul/Desktop/Thesis/Scripts/java_time
      cat output >> stats
	fi
	}	
	cd ..
}

sleep 1500

for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
	echo $j
	if [[ -f $j ]]; then
		if !([[ $j == "setup.py" ]] || [[ $j == "run.py" ]] ); then
			#compile 'Python' program
		 	echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time
		   
		#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
				if [[$i == pidigits]]; then
					/usr/bin/time -f "%e\t%M " -o output python $j <ip >pyth_op
       			cat output >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time
       			cat output >> stats
				else
      			/usr/bin/time -f "%e\t%M " -o output python3 $j <ip >pyth_op
       			cat output >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time
       			cat output >> stats
       		fi 
			fi
		fi
	#else./a.out $j
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time 
		echo 0 0 >> stats
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/pyth_time
		echo 0 0 >> stats
	fi

	#echo $?
	}
	cd ..
}

sleep 1200
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
		 	if [[ $j == "qq126_tim.py" ]] || [[ $j == "qq133_mem.py" ]] || [[ $j == "qq133_tim.py" ]] || [[ $j == "qq128_tim.py" ]] || [[ $j == "qq127_mem.py" ]] || [[ $j == "qq127_tim.py" ]] || [[ $j == "qq134_mem.py" ]] || [[ $j == "qq131_tim.py" ]] || [[ $j == "qq131_mem.py" ]] || [[ $j == "qq137_tim.py" ]] || [[ $j == "qq137_mem.py" ]] || [[ $j == "qq130_tim.py" ]]; then
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

sleep 200
cd /home/Rahul/Desktop/Thesis/Scripts
gcc make_table_time.c
./a.out >time_misc