# code chef - easy - commute - commute.py

t = int(raw_input())

for iter in range(t):
    n = int(raw_input())
    t = 0
    for i in range(n):
        x, l, f = map(int, raw_input().split())
        if t <x:
            t = x
        #print "t=", t
        trains = (t-x+f-1)//f
        #print "trains=", trains
        t = x+trains*f
        #print "train leaves at", t
        t += l
        #print "train arrives next station at ", t
        #print t
    print t
        
    