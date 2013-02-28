def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)



def main():
    T=int(input())
    for _ in range(T):
        a, b = raw_input().split()
        print(gcd(int(a),int(b)))


if __name__=='__main__':
    main()