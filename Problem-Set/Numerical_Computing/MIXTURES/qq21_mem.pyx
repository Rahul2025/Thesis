#!/usr/bin/python

from sys import stdin

def solve(n, a) :
	dp1 = [[100000000] * (n+1) for x in range(n+1)]
	dp2 = [[100000000] * (n+1) for x in range(n+1)]
	
	for i in range(n) :
		dp1[i][i] = a[i]
		dp2[i][i] = 0
		
	for j in range(2, n+1) :
		for i in range(n-j+1) :
			v = i + j - 1
			dp2[i][v] = 100000000
			k = i
			while k < v :
				q = dp2[i][k] + dp2[k+1][v] + dp1[i][k] * dp1[k+1][v]
				if q < dp2[i][v] :
					dp2[i][v] = q
					dp1[i][v] = (dp1[i][k] + dp1[k+1][v]) % 100
				k += 1
				
	print dp2[0][n-1]

def main() :
	all_input = stdin.readlines()
	
	index = 0
	while index < len(all_input) :
		n = int(all_input[index][:-1])
		index += 1
		a = [int(x) for x in all_input[index][:-1].split()]
		index += 1
		solve(n, a)

if __name__ == '__main__' :
	main()