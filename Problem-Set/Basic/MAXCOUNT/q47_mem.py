def ff(t,v):
    if t[1]<v[1]:
        return 1
    elif t[1]>v[1]:
        return -1
    else:
        if int(t[0])>int(v[0]):
            return 1
        elif int(t[0])<int(v[0]):
            return -1
        else:
            return 0

cases = input()
for i in range(cases):
    tam = input()
    table = {}
    numbers = raw_input()
    numbers = numbers.split()
    for number in numbers:
        if number in table:
            table[number]+=1
        else:
            table[number]=1
    res = sorted(table.items(), ff)
    print res[0][0],res[0][1]