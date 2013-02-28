# CodeChef
# Practice
# Easy
# Cleaning Up

ntc = int(raw_input())

for cti in range(ntc):
    jc, fc = map(int, raw_input().split())
    fl = map(int, raw_input().split())
    fl.sort()
    fl.append(-1)
    pi, fi = 0, 0
    res = [[], []]

    for ji in range(1, jc + 1):
        if ji == fl[fi]:
            fi += 1
        else:
            res[pi].append(ji)
            pi ^= 1

    for rl in res:
        print ' '.join(map(str, rl))