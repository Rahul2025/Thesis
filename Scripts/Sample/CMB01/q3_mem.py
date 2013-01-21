#by ksdthegr8

def reverse(num):
    d = 1
    f = 0
    e = 0
    g = '0'
    h = 0
    for x in range(len(str(num))):
        d = d * 10
        f = d / 10
        e = int((num % d - num % f) / f)
        g = g + str(e)
        h = int(g)
    return(h)

n = int(input())
for x in range(n):
    l = input()
    (a1,b1) = l.split(' ')
    a, b = int(a1), int(b1)
    a2,b2 = reverse(a), reverse(b)
    c = reverse(a2+b2)
    print(c)
    