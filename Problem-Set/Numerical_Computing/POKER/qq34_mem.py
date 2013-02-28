#!/usr/bin/python

from sys import stdin

def GetTrueValue(x):
    try:
        x = int(x)
        return x
    except:
        if x == 'T':
            return 10
        elif x == 'J':
            return 11
        elif x == 'Q':
            return 12
        elif x == 'K':
            return 13
        elif x == 'A':
            return 14

def GetSuitValue(x):
    if x == 'H':
        return 0
    elif x == 'C':
        return 1
    elif x == 'S':
        return 2
    return 3

def SortCards(c1, c2):
    if GetTrueValue(c1) < GetTrueValue(c2):
        return -1
    return 1

def IdentifyHand(y, s):
    triple = False
    pair = 0
    flush = 0
    straight = 0
    four = False

    if max(s) == 5:
        flush = True

    last = False
    for i, c in enumerate(y):
        if straight != 5:
            if not last and c == 1:
                last = True
                straight += 1
            elif last and c == 1:
                straight += 1
            else:
                last = False
                straight = 0

        if c == 4:
            four = True 
        elif c == 3:
            triple = True
        elif c == 2 and i != 1:
            pair += 1

    if flush and straight == 5 and y[10] == 1 and y[14] == 1:
        return 'royal flush'
    elif flush and straight == 5:
        return 'straight flush'
    elif straight == 5:
        return 'straight'
    elif four:
        return 'four of a kind'
    elif triple and pair == 1:
        return 'full house'
    elif flush:
        return 'flush'
    elif triple:
        return 'three of a kind'
    elif pair == 2:
        return 'two pairs'
    elif pair == 1:
        return 'pair'
    else:
        return 'high card'
            
if __name__ == '__main__':
    cases = int(stdin.readline())

    while cases > 0:
        cases -= 1
        y = stdin.readline().strip().split()
        y = sorted(y, SortCards)
        
        s = [0] * 4
        lst = [0] * 15

        for y1 in y:
            s1, s2 = y1[:-1], y1[-1:]
            
            lst[GetTrueValue(s1)] += 1
            s[GetSuitValue(s2)] += 1

            if s1 == 'A':
                lst[1] += 1

        print IdentifyHand(lst, s)