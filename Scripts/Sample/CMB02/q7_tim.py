def reverse(x):
    x=str(x)
    temp1=[]
    for i in range(len(x)):
        temp1.append(x[len(x)-i-1])
    temp3=''.join(temp1)
    return (x==temp3)

n=int(input())
cases=[]
for i in range(n):
    cases.append(int(input()))
results=[]
for j in range(n):
    temp=cases[j]+1
    while not(reverse(temp)):
        temp=temp+1
    print(temp)

