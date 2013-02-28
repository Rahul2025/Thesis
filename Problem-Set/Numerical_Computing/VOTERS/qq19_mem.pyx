line = raw_input()
(n1, n2, n3) = line.split(" ")
n1 = int(n1)
n2 = int(n2)
n3 = int(n3)

def read(n):
    l = []
    for i in range(n):
        l.append(int(raw_input()))
    return l

l1 = read(n1)
l2 = read(n2)
l3 = read(n3)

l = l1
l.extend(l2)
l.extend(l3)
l.sort()

solution = {}
for i in range(len(l)):
    if not solution.has_key(l[i]):
        solution[l[i]] = 1
    else:
        solution[l[i]] += 1

s = []
for k in solution:
    if solution[k] >= 2:
        s.append(k)

s.sort()

print len(s)
for i in s:
    print i

