n=int(raw_input())
while n>0:
    list=raw_input()
    list=list.split()
    if (list[1] in list[0]):
        print 1
    else:
        print 0
    n=n-1