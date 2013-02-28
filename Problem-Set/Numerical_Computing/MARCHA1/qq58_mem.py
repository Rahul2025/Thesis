#!/usr/bin/env python

def reccheck(changelist, sum):
    r=[]
    no_forms = 0
    length = len(changelist)
    if (sum == changelist[0]):
        return True
    else:
        if (sum > changelist[0]):
            if (length > 1):
                if (reccheck(changelist[1:], sum)):
                    return True
                if (reccheck(changelist[1:], sum - changelist[0])):
                    return True
    return False


def main():
    import sys
    lineno = 0
    
    #infile = open("out.txt")
    infile = sys.stdin
    
    line = infile.readline()
    
    t = int(line) # No of test cases

    for i in range(0,t):
        line = infile.readline()
        base = line.partition(" ")
        n = int(base[0]) # No of notes
        m = int(base[2]) # Money asked for
        
        a = []
        for j in range(0, n):
            a.append(int(infile.readline()))
        a.sort()
        if (reccheck(a, m)):
            print "Yes"
        else:
            print "No"

if __name__ == '__main__':
    main()