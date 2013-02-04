#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Scripts
awk 'NR % 4 == 3 || NR % 4 == 0' c_run >c_op_tim
awk 'NR % 4 == 3 || NR % 4 == 0' cpp_run >cpp_op_tim
awk 'NR % 4 == 3 || NR % 4 == 0' hs_run >hs_op_tim

gcc runtime.c
./a.out
