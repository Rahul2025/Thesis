t=int(input())
tt=raw_input()
while t>0:
    t=t-1
    a=raw_input()
    start=int(a)-(9*len(a))
    a=int(a)
    flag=0
    while start<a:
        digsum=sum(list(map(int,list(str(start)))))
        nw=digsum+start
        if nw==a:
            print(start)
            flag=1
            break
        else:
            start=start+1
    if flag:
        continue
    else:
        print("NONE")