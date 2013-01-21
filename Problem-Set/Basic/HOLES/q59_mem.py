def holes(str):
	found=0
	for hole in ['Q','R','O','P','A','D']:
		if str.count(hole)>0:
			found+=str.count(hole)
	if str.count('B')>0:
		found+=str.count('B')*2
	return found

amount = input()
for i in range(0, amount):
	test = raw_input()
	print holes(test)