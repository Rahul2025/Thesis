import sys
 
n = int(sys.stdin.readline())
alphabet = "abcdefghijklmnopqrstuvwxyz"
alphabetR = alphabet[::-1]
for i in xrange(n):
	K = int(sys.stdin.readline())
	reps = K / 25
	cut = K % 25
	if cut != 0:
		answer = alphabet[:cut+1][::-1]
	else:
		answer = ""
	answer += alphabetR * reps
	print answer