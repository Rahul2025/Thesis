#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts


rm /home/Rahul/Desktop/Thesis/Scripts/all_time
rm /home/Rahul/Desktop/Thesis/Scripts/final_cmp_mem.csv
rm /home/Rahul/Desktop/Thesis/Scripts/final_run_mem.csv
rm /home/Rahul/Desktop/Thesis/Scripts/final_cmp_tim.csv
rm /home/Rahul/Desktop/Thesis/Scripts/final_run_tim.csv

echo "c,cpp,haskell,java,python,cython" >final_cmp_mem.csv
echo "c,cpp,haskell,java,python,cython" >final_cmp_tim.csv
echo "c,cpp,haskell,java,python,cython" >final_run_mem.csv
echo "c,cpp,haskell,java,python,cython" >final_run_tim.csv

sleep 100
bash time_basic.sh

sleep 250
bash time_graph.sh


sleep 300
bash time_misc.sh

sleep 200
bash time_np.sh

sleep 300
bash time_numerical.sh

sleep 100
bash time_web.sh

cat time_basic >> all_time
cat time_graph >> all_time
cat time_misc >> all_time
cat time_np >> all_time
cat time_numerical >> all_time
cat time_web >> all_time
