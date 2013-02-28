def compare(string):
    string=string.split()
    temp1=sorted(string[0])
    temp2=sorted(string[1])
    if temp1==temp2:
        return 'YES'
    else:
        return 'NO'

n=int(input())
cases=[]
for i in range(n):
    cases.append(raw_input())

for j in range(n):
    print(compare(cases[j]))