import sys
readln = sys.stdin.next
write = sys.stdout.write

try:
  import psyco
  psyco.full()
except ImportError:
  pass

def beanstalk():
  nr_of_piles = int(readln())
  leaves = map(int, readln().split())
  if leaves == [1]:
    return True
  leaves.reverse()
  stems = 0
  for nr in leaves[:-1]:
    #print "Stems:", stems, "  Leaves:", nr
    stems, md = divmod(stems + nr, 2)
    if md != 0:
      return False
  #print "Stems:", stems, "  Leaves:", leaves[-1]
  return stems == 1

def process():
  nr_of_cases = int(readln())
  for _ in xrange(nr_of_cases):
    print ["No", "Yes"][beanstalk()]

process()