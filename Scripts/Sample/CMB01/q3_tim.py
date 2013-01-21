def rever(s):
    t=''
    if len(s)==1:
        return s
    l=len(s)-1
    while l>=0:
        t=t+s[l]
        l=l-1
    return t
t=int(input())
while t>0:
    t=t-1
    a,b=input().split()
    a=rever(a)
    b=rever(b)
    a=int(a)
    b=int(b)
    c=a+b
    c=str(c)
    c=rever(c)
    print(int(c))