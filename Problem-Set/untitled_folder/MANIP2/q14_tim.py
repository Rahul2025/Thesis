#/usr/bin/python

import os
import sys

l = sys.stdin.readlines()
N = int(l[0])
l.remove(l[0])
q = map(int, l)
for i in range(len(q)):
	n = q[i]
	j = 5
	ans = 0
	while n>0:
		rem = n%2
		ans = ans+rem*j
		j = j*5
		n=n/2
	print ans
	

	
	
	






