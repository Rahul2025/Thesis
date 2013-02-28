from sys import stdin
data = stdin.readlines()
for line in data[1:]:
    r = line.strip()
    j = -1
    count = 1
    x = len(r)
    for j in range(0, (x / 2)):
        if(r[j] == '?' and r[-1-j] == '?'):
            count = count*26%10000009
            continue
        if r[j] != r[x - 1 - j] and r[j] != '?' and r[x - 1 - j] != '?':
            count = 0
            break
        if r[j] != '?' and r[x - 1 - j] != '?':
            continue
        else:
            count *= 1
    if x % 2 == 1:
        if r[j + 1] == '?':
            count = count*26 % 10000009
    print count