t=input()
while t:
    s=raw_input()
    r=raw_input()
    l=len(r)
    count=0
    for i in xrange(l):
        if r[i] in s:
            count+=1
    print count
    t-=1