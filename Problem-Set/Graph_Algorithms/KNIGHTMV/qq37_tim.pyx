t = input()
while t>0:
	m = raw_input()
	if len(m)!=5 or m[0]<'a' or m[0]>'h' or m[3]<'a' or m[3]>'h' or m[1]<'1' or m[1]>'8' or m[4]<'1' or m[4]>'8' or m[2]!='-':
		print "Error"
	elif (abs(ord(m[0])-ord(m[3]))==1 and abs(ord(m[1])-ord(m[4]))==2) or (abs(ord(m[1])-ord(m[4]))==1 and abs(ord(m[0])-ord(m[3]))==2):
		print "Yes"
	else:
		print "No"
	t = t - 1