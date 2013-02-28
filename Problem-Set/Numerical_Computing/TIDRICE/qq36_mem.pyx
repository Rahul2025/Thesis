a=input()
b={}
i=0
k=[]
while i<a:
    c=input()
    p=0
    f=[]
    b={}
    while p<c:
        x=raw_input()
        x,y=x.split(" ")
        if y=='+':   
            b[x]=1
        else:b[x]=-1
        p=p+1
    f=b.keys()
    h=len(f)
    j,c=0,0
    while j<h:
        c=c+b[f[j]]
        j=j+1
    k.append(c)
    i=i+1
g=0
while g<len(k):
    print k[g]
    g=g+1