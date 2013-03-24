#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts
rm /home/Rahul/Desktop/Thesis/Scripts/all_time

bash time_basic.sh
sleep 300
bash time_graph.sh
sleep 2000
bash time_misc.sh
sleep 600
bash time_np.sh
sleep 300
bash time_numerical.sh
bash time_web.sh

cat time_basic >> all_time
cat time_graph >> all_time
cat time_misc >> all_time
cat time_np >> all_time
cat time_numerical >> all_time
cat time_web >> all_time