import sys

def gen(m,n):
	if m==1:
		m+=1
	if m<=2<=n:
		yield 2
	if m%2==0:
		m+=1
	isp=set(xrange(m,n+1,2));
	sq=int(n**0.5)+1
	for i in xrange(3,sq,2):
		if i==3 or (i%3)!=0:
			if i in isp:
				yield i
			isp.difference_update(xrange((m//i)*i,n+1,i))
	for i in sorted(isp):
		yield i

t=int(raw_input())
while t:
	t-=1;
	m,n=[int(i) for i in raw_input().split()]
	for i in gen(m,n):
		print i
	print 