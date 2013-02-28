def getCount(arr):
    dic={}
    for x in arr:
        if x in dic:
            dic[x]+=1
        else:
            dic[x]=1

    maxCount=0
    for x in dic:
        if dic[x]>maxCount:
            maxCount=dic[x]

    maxElems=[]
    for x in dic:
        if dic[x]==maxCount:
            maxElems.append(x)

    maxElems.sort()
    return maxElems[0],maxCount

T=int(raw_input())
for x in range(T):
    l= int(raw_input())
    arr= raw_input().split()
    arr= map(int,arr)
    elem,count=getCount(arr)
    print elem,count