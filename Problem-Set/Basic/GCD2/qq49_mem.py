def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
     
n=int(input())
for x in range(n):
    s=raw_input()
    s=s.split(' ')
    a=int(s[0])
    b=int(s[1])
    g=gcd(a,b)
    print (g)
 