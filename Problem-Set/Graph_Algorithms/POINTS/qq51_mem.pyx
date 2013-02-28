def compare_point(x, y):
  if x[0] < y[0]:
    return -1
  if x[0] == y[0]:
    if x[1] == y[1]:
      return 0
    if x[1] > y[1]:
      return -1
    return 1
  return 1

def dst(p1,p2):
  xdiff = p1[0] - p2[0]
  ydiff = p1[1] - p2[1]
  
  return (xdiff**2 + ydiff**2)**(0.5)

t = int(raw_input())
for i in range(t):
  input = []
  d = 0.0
  raw_input()
  n = int(raw_input())
  for j in range(n):
    temp = raw_input().split(' ')
    input.append((int(temp[0]), int(temp[1])))
  input.sort(cmp=compare_point)
  for i in range(len(input)-1):
    d = d + dst(input[i],input[i+1])   
  print "%.2f" % d