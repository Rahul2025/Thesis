import sys
import fileinput
#import psyco
#psyco.full()

def count_permutations_of_total__bruteforce(N,A,B,C):
    a = 0
    b = 0
    c = 0
    count = 0
    while a <= A and a <= N:
        while b <= B and a + b <= N:
            while c <= C and a + b + c <= N:
                #print a,b,c,"count",count
                count = count + 1
                c = c + 1                
            b = b + 1
            c = 0
        a = a + 1
        b = 0
        #print a,b,c,"count",count
    global countres
    countres = count
    return count

def count_permutations_of_total__predictiveC(N,A,B,C):
    #print "count_permutations_of_total__predictiveC (",N,A,B,C,")","...",
    a = 0
    b = 0
    count = 0
    while a <= A and a <= N:
        while b <= B and a + b <= N:
            c = N - a - b + 1
            if C < c:
                c = C + 1
            elif c < 0:
                c = 0
            count = count + c
            b = b + 1
        a = a + 1
        b = 0
    
    #print "count",count
    return count

if __name__ == '__main__':
    fi = fileinput.input("""-""")
    #print(dir(fi))
    inputcount = int(fi.next().strip())
    for line in fi:
        (n,a,b,c) = line.split(" ")
        print count_permutations_of_total__predictiveC(int(n),int(a),int(b),int(c))
        inputcount = inputcount - 1
        if inputcount == 0:
            break
    fi.close()