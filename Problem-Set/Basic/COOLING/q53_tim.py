import sys

def main():
  n = int(sys.stdin.readline())
  for i in xrange(n):
    l = int(sys.stdin.readline())
    wp = map(int,sys.stdin.readline().split())
    wl = map(int,sys.stdin.readline().split())
    wp.sort()
    wl.sort()

    j = 0
    lp = wp.pop(0)
    for r in wl:
      if lp <= r:
        j += 1
        if wp: lp = wp.pop(0)
    print j

main()