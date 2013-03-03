import sys, os, bisect

total = int(sys.stdin.readline())

heights = [int(x) for x in sys.stdin.readline().split()]

length = len(heights)

sortedh = []

#print heights

count = 0
for i in xrange(length):
	x = bisect.bisect_left(sortedh, heights[i])		
	#print x
	count += len(sortedh) - x

	sortedh.insert(x, heights[i])

#print sortedh
print count
		
		