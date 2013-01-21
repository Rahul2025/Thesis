import random

def findCols(rows, grid, C):
    total, cols = 0, []
    for c in xrange(C):
        tmp = sum([grid[r][c] for r in rows])
        if tmp > 0:
              cols.append(c)
              total += tmp
    return cols, total
               
def hillClimbing(grid, R, C):
    best = 0
    bestRows = [0]
    bestCols = [0]

    for r in xrange(R):
        for c in xrange(C):
            if(best < grid[r][c]):
                best, bestRows[0], bestCols[0] = grid[r][c], r, c
    for i in xrange(50):
        rows = random.sample(xrange(R), random.randint(1, R))
        cols, total = findCols(rows, grid, C)
        if total > best:
            best, bestRows, bestCols = total, rows, cols

                  
    print len(bestRows), len(bestCols)
    print ' '.join(map(str, sorted(bestRows)))
    print ' '.join(map(str, sorted(bestCols)))              

R, C = map(int, raw_input().split())
grid = [[]] * R
for i in xrange(R):
    grid[i] = map(int, raw_input().split())

hillClimbing(grid, R, C)