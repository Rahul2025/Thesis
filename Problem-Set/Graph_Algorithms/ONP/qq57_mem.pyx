def getE(e):
	i = 0
	o = ""
	exp = ""
	operator = False
	
	while i < len(e):
	
		if operator:
			o = e[i]
			operator = False
		else:
			operator = True
			if e[i] == '(':
				j = i
				count = 0
				while i < len(e):
					if e[i] == '(':
						count += 1
					elif e[i] == ')':
						count -= 1
						if count == 0:
							break
					i += 1
				exp += getE(e[j+1:i])+o
			else:
				exp += e[i]+o
		i += 1
	return exp
for n in xrange(long(raw_input())):
	s = raw_input()
	print getE(s)
				