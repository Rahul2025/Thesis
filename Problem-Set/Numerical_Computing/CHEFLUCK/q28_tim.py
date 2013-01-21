import sys
def read_int():
    try:
        num = sys.stdin.readline()
    except KeyboardInterrupt:
        return None
    return int(num)

if __name__ == "__main__":
    n = read_int()
    for i in range(0, n):
        N = read_int()
        if N%7 == 0:
            print N
            continue
        rem = N%7
        needed = 7*(rem%4)
        if (needed+rem) <= N:
            print N-(needed+rem)
        else:
            print -1