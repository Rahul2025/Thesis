#!/bin/bash

cd /home/Rahul/Desktop/Thesis/Scripts
awk 'NR % 4 == 3 || NR % 4 == 0' hs_run >op_tim

gcc hs_runtime.c
./a.out
