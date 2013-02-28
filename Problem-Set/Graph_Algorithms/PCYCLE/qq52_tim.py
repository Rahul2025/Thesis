import sys

def main():
  n = int(sys.stdin.readline())
  p = map(int, sys.stdin.readline().split())

  s = 0 # First unvisited

  allpaths = []
  while s < n:
    path = []
    path.append(s+1) # Visit position
    i = p[s] - 1 # Next position
    while p[i] != p[s]: # Not a cycle
      path.append(i+1) # Visit position
      np = p[i] - 1 # Next position
      p[i] = 0 # Mark this position as visited
      i = np
    path.append(s+1)
    allpaths.append(path)

    s += 1
    while s < n and p[s] == 0: s += 1

  print len(allpaths)
  for p in allpaths:
    print " ".join(map(str,p))

main()