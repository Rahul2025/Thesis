#import psyco
#psyco.full()

def num_map(n,k):
    m = 0
    for i in range(k):
        if n&(1<<(i)):
                m+= (1<<(k-i-1))
    return m

def proc_case():
    (k, str) = (raw_input().strip().split())
    k = int(k)
    
    result = ' '
    result = list(result.ljust(2**k))
    
    
    for i in range(2**k):
        try:
            if result[i] == ' ':
                j = num_map(i,k)
                result[i] = str[j]
                result[j] = str[i]
        except:
            print "%d %d %d" % (i, j, k)
    
    return "".join(result)
     

def proc_all():
    n_case=int(raw_input().strip())
    for i in range(n_case):
        print '%s'%(proc_case())

proc_all()