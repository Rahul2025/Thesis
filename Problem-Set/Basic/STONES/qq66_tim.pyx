t = int(raw_input())
for i in range(0,t):
	count = 0
	j = raw_input()
	s = raw_input()
	for alphabet in s:
		if alphabet in j:
			count+=1
	print count