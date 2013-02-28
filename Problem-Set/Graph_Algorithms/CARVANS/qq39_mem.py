import sys
n=int(raw_input())
for i in range(0,n):
    cars=int(raw_input())
    L=[]
    L=sys.stdin.readline().split()
    L=map(int,L)
    count=1
    if len(L)==1:
            print count
    else:
        for j in range(0,len(L)-1):
            if L[j]<L[j+1]:
                L[j+1]=L[j]
            else:
                count +=1
                continue
        print count