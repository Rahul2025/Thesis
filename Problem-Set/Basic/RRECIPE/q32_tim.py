import math

MOD=10000009
def pal():
    count=1
    string=raw_input()
    length=len(string)
##    ev=length%2
    for x in range(int(math.ceil(length/2.0))):
##        if ev==1 and x==(length/2 +1):
##            if string[x]
            
        if ( string[x] == string[length-x-1]):
            if string[length-x-1]== '?':
               count=(count*26)%MOD
        else:
            if string[x]=='?' or string[length-x-1]=='?':
                continue
            else:
                return 0
            
    return count


T= int(raw_input())
for x in range (T):
    print pal()

        