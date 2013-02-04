#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Misc
rm /home/Rahul/Desktop/Thesis/Scripts/hs_time
rm /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
rm /home/Rahul/Desktop/Thesis/Scripts/hs_run

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
		if  [[ $i == "binary-trees" ]] || [[ $i == "binary-trees-redux" ]] || [[ $i == "fannkuch-redux" ]] || [[ $i == "fasta" ]] || [[ $i == "k-nucleotide" ]] || [[ $i == "meteor-contest" ]] || [[ $i == "n-body" ]] || [[ $i == "pidigits" ]] || [[ $i == "thread-ring" ]]; 
			then
		   	/usr/bin/time -f "%e\t%M " ghc --make -O2 -XBangPatterns -threaded $j #-o a.out 2>/dev/null 		
		elif [[ $i == "chameneos-redux" ]]; 
			then
				/usr/bin/time -f "%e\t%M " ghc --make -O2 -XBangPatterns -threaded -XCPP -XGeneralizedNewtypeDeriving $j -o a.out
		else
			/usr/bin/time -f "%e\t%M " ghc --make -O2 -XBangPatterns -threaded -funfolding-use-threshold=32 -XMagicHash -XUnboxedTuples -fexcess-precision $j -o a.out 2>/dev/null
			# -o output  ghc --make -O2 -XBangPatterns -threaded -XMagicHash  $j
			# -o output  ghc --make -O2 -XBangPatterns -fexcess-precision $j	
		fi	
	#  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
	#If there were no compilation errors, run the program
		if [[ $? -eq 0 ]]; then
			/usr/bin/time -f "%M" -o output ./a.out +RTS -N4 -RTS <ip >hs_op
      #  cat output >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
         (time ./a.out <ip >hs_op ) 2>op
      #  cat op >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
		#fi
	else 
		echo 0 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp 
		echo 0 >> /home/Rahul/Desktop/Thesis/Scripts/hs_cmp
		#cat '0' >> /home/Rahul/Desktop/Thesis/Scripts/hs_run
	fi
	#else
	#echo $?
	fi
	}
	cd ..
}

#cd /home/Rahul/Desktop/Thesis/Scripts
#bash hs_runtime_script.sh