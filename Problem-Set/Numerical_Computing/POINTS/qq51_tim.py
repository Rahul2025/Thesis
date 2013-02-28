#!/usr/bin/env python

try:
    import psyco
    psyco.full()
except ImportError: pass
import sys

from collections import defaultdict
from math import sqrt

def get_dist(x1, y1, x2, y2):
    return sqrt((x1 - x2)**2 + (y1 - y2)**2)

def get_distance(points):
    for ys in points.values():
        ys.sort(reverse=True)
    
    dist = 0
    lx = ly = None
    for x, ys in points.iteritems():
        for y in ys:
            if ly is not None:
                dist += get_dist(x, y, lx, ly)
            ly = y
            lx = x
    return dist

def main():
    T = int(sys.stdin.readline())
    for _ in xrange(T):
        points = defaultdict(list)
        sys.stdin.readline()
        N = int(sys.stdin.readline())
        for _ in xrange(N):
            x, y = map(int, sys.stdin.readline().split())
            points[x].append(y)
        print '%.2f' % get_distance(points)

main()