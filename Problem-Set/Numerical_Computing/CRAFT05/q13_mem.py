from sys import *
no = int(input())
for i in range(no):
	N= int(input())
	X,Y,Z = list(map(int,stdin.readline().split(" ")))
	r1 = (1000*X + 100*Y + 10*Z)
	for i in range(9,1,-1):
		for j in range(9,-1,-1):
			if ((j + (10000*i)+r1)%N)==0:
				print (i,j,int((10000*i+j+r1)/N))
				a=1
				break
			else:a=0
		if(a):break
	if(not a):print(0) 