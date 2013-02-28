#riled
t=int(input())
while t>0:
    t=t-1
    mp=raw_input().split()
    s=list(mp[0])
    s=list(map(ord,s))
    d=sum(s)
    d=int(d/len(s))
    print(chr(d))