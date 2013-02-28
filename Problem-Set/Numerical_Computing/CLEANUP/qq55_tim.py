import sys

def main():
  n = int(sys.stdin.readline())
  for i in xrange(n):
    n,m   = map(int, sys.stdin.readline().split())
    cmplt = map(int, sys.stdin.readline().split())

    cmplt_set = set(cmplt)
    unfin_set = set(range(1,n+1)) - cmplt_set
    unfin_lst = list(unfin_set)
    unfin_lst.sort()

    print " ".join(map(str,unfin_lst[::2]))
    print " ".join(map(str,unfin_lst[1::2]))

main()