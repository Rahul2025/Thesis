# CodeChef
# Practice
# Easy
# Three Way Communications

##pl = []

def gds(ai, bi):
    global pl
    dx, dy = pl[ai][0] - pl[bi][0], pl[ai][1] - pl[bi][1]
    return dx * dx + dy * dy

ntc = int(raw_input())

for cti in range(ntc):
    rv = int(raw_input())
    pl = [map(int, raw_input().split()) for pi in range(3)]
    dsl = [gds(0, 1), gds(0, 2), gds(1, 2)]
    dsl.sort()
    print 'yes' if dsl[1] <= rv * rv else 'no'