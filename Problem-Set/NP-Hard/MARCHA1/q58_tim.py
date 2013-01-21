import sys

def main():
  for (n, m, coins) in testcases():
    can_make = set([0])
    for c in coins:
      upd = set()
      for v in can_make:
        if v+c <= m: upd.add(v+c)
      can_make |= upd
      if m in can_make: break

    if m in can_make:
      print "Yes"
    else:
      print "No"

def testcases(cin = sys.stdin):
  t = int(cin.next())

  for _ in xrange(t):
    n, m = map(int, cin.next().split())
    coins = [int(cin.next()) for _ in xrange(n)]

    yield (n, m, coins)

if __name__ == "__main__": sys.exit(main())
