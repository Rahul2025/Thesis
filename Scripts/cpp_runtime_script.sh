#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Scripts
awk 'NR % 4 == 3 || NR % 4 == 0' cpp_run >op_tim

gcc c_runtime.c
./a.out
