#!C:\Python27
t = int(raw_input())
while t>0:
    n , c = (raw_input()).split()
    c = int(c)
    s = raw_input()
    su = 0
    for candycount in s.split():
        su += int(candycount)
    if su<=c:
        print "Yes"
    else:
        print "No"
    t-=1