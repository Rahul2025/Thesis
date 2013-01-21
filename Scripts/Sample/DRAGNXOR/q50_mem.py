import sys
def ones(num):
    count=0
    while num>0:
        if num%2 == 1:
            count=count+1
        num/=2
    return count

if __name__=='__main__':
    t=int(raw_input())
    for testcase in range(t):
        n,a,b=map(int,sys.stdin.readline().strip().split(' '))
        zeros=ones(a)+ones(b)-n
        zeros=(-zeros,zeros)[zeros>0]
        answer=0
        p = 2**(n-1)
        rones=n-zeros
        while rones>0:
            answer+=p
            rones -=1
            p/=2
        print answer
        
        
  