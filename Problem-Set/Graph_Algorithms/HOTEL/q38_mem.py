def process(N, A, D):
    H = [0] * 1000
    for n in xrange(N):
        for h in xrange(A[n], D[n]):
            H[h] += 1
    return max(H)

def main():
    T = int(raw_input())
    for t in xrange(T):
        N = int(raw_input())
        A = map(int, raw_input().split())
        D = map(int, raw_input().split())
        print process(N, A, D)

main()