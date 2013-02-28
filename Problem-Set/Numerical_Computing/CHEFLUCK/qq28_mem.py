T=int(raw_input())
for i in range(T):
	N=int(raw_input())
	for j in range(7):
		a=N-j*4
		if a>=0 and a%7 ==0:
			print str(a)
			break
		if j==6:
			print '-1'
	