for i in *
{
	echo $i
	cd $i
	for j in *.py
	{
	if [[ -f $j ]]; then
		if !([[ $j == "setup.py" ]] || [[ $j == "run.py" ]]); then
			#compile 'Cython' program
		 	echo 0 0 >> /home/Rahul/Desktop/Thesis/Problem-Set/cyth_time
		   echo $j
			#If there were no compilation errors, run the program
			if [[ $? -eq 0 ]]; then
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