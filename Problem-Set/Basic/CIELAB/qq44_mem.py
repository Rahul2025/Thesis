import sys
     
a,b = map(int, sys.stdin.readline().split())
diff = a - b
if diff % 10 == 9:
	answer = diff - 1
else:
	answer = diff + 1
print answer