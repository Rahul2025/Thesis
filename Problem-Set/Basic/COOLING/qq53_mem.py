import sys

lines = sys.stdin.readlines()
cases = int(lines[0])
count = 1

for case in range(cases) :
    N = int(lines[count])
    count = count+1
    pies = map(int,lines[count].split())
    count = count + 1
    racks = map(int,lines[count].split())
    count = count + 1
    racks.sort()
    pies.sort()
    opt = [[0 for col in range(N)] for row in range(N)]
    for i in range(N) :
        O = opt[i]
        for j in range(i,N) :
            if i == 0 :
                if pies[i] <= racks[j] :
                    O[j] = 1
            else :
                if pies[i] <= racks[j] :
                    O[j] = max(opt[i-1][j],opt[i-1][j-1]+1)
                else :
                    O[j] = opt[i-1][j]
    print opt[N-1][N-1]