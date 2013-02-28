#! /usr/bin/python

def find_ways(n,k):
    #if n==k :
    #    return 1 # if colors == balls
    #else:
    extra_bal=n - k
    #    if extra_bal==1:
    #        return k 
    #    else:
    return permute(extra_bal+k-1,extra_bal,k-1)


def permute(n,r1,r2):
    #permutation with repitations
    max=r2
    num=1
    den=1
    i=1
    if r1 > r2:
        max=r1
    while True:
        if n==max:
            break
        else:
            num=num*n
            #print n,"num" ,num
            n=n-1
            den=den*i
            #print i,"den" ,den
            i=i+1 
    
    return num/den


    
   

def input_read(line):
    args=line.split(' ')
    n=int(args[0])
    k=int(args[1])
    print find_ways(n,k)


no=input()
i=0
while i < no:
    inp=raw_input()
    input_read(inp)
    i+=1 
    