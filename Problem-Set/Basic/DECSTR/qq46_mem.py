# CodeChef
# Practice
# Easy
# Decreasing String

##fs = map(chr, range(ord('z'), ord('a') - 1, -1))
fs = ''.join([chr(cc) for cc in range(ord('z'), ord('a') - 1, -1)])
ntc = int(raw_input())

for cti in range(ntc):
    dl = int(raw_input())
    res = dl / 25 * fs

    if dl % 25:
        res = fs[-(dl % 25 + 1):] + res

    print res