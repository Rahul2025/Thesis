# CodeChef
# Practice
# Easy
# The Morning Commute

ntc = int(raw_input())

for cti in range(ntc):
    ct = 0
    lc = int(raw_input())

    for li in range(lc):
        xv, lv, fv = map(int, raw_input().split())
        ct = xv + max(0, (ct - xv + fv - 1) / fv) * fv + lv

    print ct