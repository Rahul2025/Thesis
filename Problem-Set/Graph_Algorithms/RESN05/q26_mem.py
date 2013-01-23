#!/usr/bin/python
"Solve the Summing Subsets problem at CodeChef"
MODVALUE = 8388608  # 2 ** 23
import sys
def main():
 testcases = int(raw_input())
 for testcase in xrange(testcases):
  n = int(raw_input())
  print s(n)
def f(n):
 """empirically, using pencil and paper, you can come up with this formula:

    f(n) = sum(xrange(n + 1)) * (2 ** (n - 1))
 """
 total = 0
 for i in xrange(n + 1):
  total = (total + i) % MODVALUE
 for i in xrange(1, n):
  total = (total + total) % MODVALUE
 #print >>sys.stderr, 'f(%d) = %d' % (n, total)
 return total
def s(n):
 """any number over 22 produces a number f(n) with no bits below 2 ** 23 set

    therefore all s(n>22) is MODVALUE - 1
 """
 if (n > 22): return MODVALUE - 1
 total = 0
 for i in xrange(1, n + 1):
  total = (f(i) + total) % MODVALUE
 return total
main()