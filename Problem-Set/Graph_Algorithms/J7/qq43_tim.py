# p =pow((s*6),0.5)
n = int(raw_input());
volumes = []

def solve(p, s):
	x = (p-pow(pow(p,2)-24*s,0.5))/12
	y = (p-8*x)/4
	return round(x*x*y,2)

for i in range(n):
	input = list(raw_input().split(" "))
	p = int(input[0])
	s = int(input[1])
	vol=solve(p,s)
	volumes.append(vol)

for v in volumes:
	print v