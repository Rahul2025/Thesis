#by ksdthegr8

def rev(num):
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
    count = 0
    p = int(input())
    q = rev(p)
    while p != q :
        count = count + 1
        p = p + q
        q = rev(p)
    print(count, p)
        
    
    