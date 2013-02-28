from sys import stdin, stdout
from math import fabs

#import psyco
#psyco.full()

def tlg():
    lead = 0
    maxLead = 0
    player = 0
    for i in xrange(int(stdin.readline())):
        s, w = stdin.readline().split()
        lead += int(s) - int(w)
        if fabs(lead) > fabs(maxLead):
            maxLead = lead
    result = []
    if maxLead > 0:
        result.append(str(1) + ' ')
    else:
        result.append(str(2) + ' ')
    result.append(str(int(fabs(maxLead))))
    print ''.join(result)

tlg()