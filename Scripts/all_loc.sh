#!/bin/bash

#input directory
cd /home/Rahul/Desktop/Thesis/Scripts
rm /home/Rahul/Desktop/Thesis/Scripts/all_loc
rm /home/Rahul/Desktop/Thesis/Scripts/final_ranks

bash loc_basic.sh >loc
bash loc_graph.sh >loc
bash loc_misc.sh >loc
bash loc_np.sh >loc
bash loc_numerical.sh >loc
bash loc_web.sh >loc

cat loc_basic >> all_loc
cat loc_graph >> all_loc
cat loc_misc >> all_loc
cat loc_np >> all_loc
cat loc_numerical >> all_loc
cat loc_web >> all_loc