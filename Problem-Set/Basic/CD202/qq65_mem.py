def decode2(S):
    Q = ''
    i = 0
    while i < len(S):
        v = S[i]
        if v in 'aeiou': i += 2
        Q += v
        i += 1
    return Q

def main():
    while True:
        try:
            S = raw_input()
        except:
            break
        print decode2(S)

main()