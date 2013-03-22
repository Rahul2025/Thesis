#usr/bin/python

def main():
	score= []
	lead= 0
	x= 0
	y= 0
	n= input()
	while n:
		string= raw_input()
		score= string.split()
		x += int(score[0])
		y += int(score[1])
		if x > y:
			if lead < x-y:
				lead = x-y
				w= 1
		if x<y:
			if lead < y-x:
				lead= y-x
				w= 2
		n -= 1
	print w, lead


main()