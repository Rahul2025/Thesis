import sys
#import psyco
#psyco.full()

def main() :
	lines = sys.stdin.readlines()
	cases = int(lines[0])
	count = 1
	board = [[0 for col in xrange(1000)] for row in xrange(1000)]
	for case in xrange(cases) :
		N = int(lines[count])
		count = count + 1
		pawn = 2*(case+1)
		knight = pawn + 1
		for i in xrange(N) :
			s = lines[count]
			count = count + 1
			board_temp = board[i]
			for j in xrange(N) :
				if s[j] == 'K' :
					board_temp[j] = knight
				elif s[j] == 'P' :
					board_temp[j] = pawn
		best = [[0 for col in xrange(N)] for row in xrange(N)]
		broken = False
		for i in xrange(N-1,-1,-1) :
			for j in xrange(N-1,-1,-1) :
				p1 = 0
				p2 = 0
				p3 = 0
				p4 = 0
				# point 1 index : j - 2, i + 1
				if 0 <= j - 2 <= N - 1 and 0 <= i + 1 <= N - 1 :
					p1 = best[j-2][i+1]
				# point 2 index : j + 2, i + 1
				if 0 <= j + 2 <= N - 1 and 0 <= i + 1 <= N - 1 :
					p2 = best[j+2][i+1]
				# point 3 index : j + 1, i + 2
				if 0 <= j + 1 <= N - 1 and 0 <= i + 2 <= N - 1 :
					p3 = best[j+1][i+2]
				# point 4 index : j - 1, i + 2
				if 0 <= j - 1 <= N - 1 and 0 <= i + 2 <= N - 1 :
					p4 = best[j-1][i+2]
				pmax = max(p1,p2,p3,p4)
				if board[j][i] == pawn :
					best[j][i] = pmax + 1
				elif board[j][i] == knight :
					best[j][i] = pmax
					print pmax
					broken = True
					break
				else :
					best[j][i] = pmax
			if broken :
				break

main()