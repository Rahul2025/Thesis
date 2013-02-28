for a in range(10):
    l=[]
    for b in range(10):
        tc=int(input())
        m=tc%42
        if m in l:
            continue
        else:
            l.append(m)
    print (len(l))