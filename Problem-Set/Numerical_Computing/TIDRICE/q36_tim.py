#!C:\Python27
t = int(raw_input())
while t>0:
    n = int(raw_input())
    di = {}
    score = 0
    for i in range(n):
        user , vote = raw_input().split()
        di[user] = vote
    for key , val in di.items():
        if val=="+":
            score+=1
        else:
            score-=1
    print score
    t-=1