#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Problem-Set/Basic
#cd /home/Rahul/Desktop/Thesis/Scripts/Sample1/S2


#sed 's/.$//' /home/Rahul/Desktop/Thesis/Scripts/Sample1/S2/temp
#sed 's/\(.*\)./\1/' stat
for i in *
{
	echo $i
	cd $i
#	rm temp
	for j in *
	{
			if   [[ ${#j} == 4 ]] || [[ ${#j} == 3 ]];
				then
	#				echo $j
					id=${j#"q"}
					echo $id","
				fi
				
#			if [[ $j == "stats" ]]
			
	}
#	echo $id"," | cat - stats > temp
#	echo "$(echo 'task goes here' | cat - todo.txt)" > todo.txt
#	mv temp stats
	echo $id","| cat - stats > temp 
#	mv temp stats
	sed 's/\(.*\)./\1/' temp >stats
	rm temp
	
	cd ..
}
