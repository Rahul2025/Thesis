#!/usr/bin/python
precomp = {}

def coin_val(c):
	if c in precomp:
		return precomp[c]

	if c > 11:
		temp = coin_val(c // 2) + coin_val(c // 3) + coin_val(c // 4)
		temp = max((c, temp))
		precomp[c] = temp
		return temp
	
	precomp[c] = c
	return c

try:
	while True:
		print coin_val( int( raw_input() ) )
except:
	pass