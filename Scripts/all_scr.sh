#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts
#rm /home/Rahul/Desktop/Thesis/Scripts/all_loc
#rm /home/Rahul/Desktop/Thesis/Scripts/final_ranks

bash c_script.sh
echo "------------------------------------------------------------------------------"
bash cpp_script.sh
echo "------------------------------------------------------------------------------"
#bash java_script.sh
echo "------------------------------------------------------------------------------"
bash hs_script.sh
echo "------------------------------------------------------------------------------"
#bash pyth_script.sh
