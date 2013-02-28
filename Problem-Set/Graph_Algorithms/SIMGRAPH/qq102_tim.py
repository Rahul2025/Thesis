import sys
 
def getGraph(v):
    g = {}
    t = 0
    for i in range(v):
        k = raw_input().split();
        for j in range(len(k)):
            k[j] = int(k[j])
        g[i] =k
        t += sum(g[i])
    return g,int(t/2)
 
 
def comEdges(u,v):
    c=0
    for i in range(len(u)):
        if((u[i]-v[i])>=0):
            c += min(u[i],v[i]) 
    return c
 
def getSimilar(g1,g2,e1,e2,v):
    common = 0
    for i in range(v):
        common += comEdges(g1[i],g2[i])
    '''print(int((2*common)/(e1+e2)))'''
    return
 
def isSimilar(v):
    g1,e1 = getGraph(v)
    g2,e2 = getGraph(v)
    '''print(g1,e1)
    print(g2,e2)'''
    getSimilar(g1,g2,e1,e2,v)
    a=[i+1 for i in range(v)]
    print(' '.join(map(str,a)))
    print(' '.join(map(str,a)))
    return
 
def main():
    t=int(raw_input())
    while t>0:
        n=int(raw_input())
        isSimilar(n)
        t-=1
    return
 
if __name__ == '__main__':
    main()
    sys.exit()