NAME = "P4"
try:
    inFile = open(NAME+".txt")
except:
    pass

def getLine():
    try:
        return inFile.readline()
    except:
        return raw_input()

cases = int(getLine())
for _ in range(cases):
    n = int(getLine())
    ans = n/2048
    ans += bin(n%2048)[2:].count("1")
    print ans