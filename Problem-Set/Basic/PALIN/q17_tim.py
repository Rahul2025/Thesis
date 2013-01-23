#!/usr/bin/env python

def process(N):

    L = len(N)

    left   = N[:L/2]
    center = L % 2 and N[L/2] or ''
    right  = left[::-1]
    P      = left + center + right

    # if reversing the left part to the right makes a greater integer :
    if P > N:
       return P

    # if it doesn't, but the center is not a '9', it's not a big deal :
    if center and center != '9':
       center = str(int(center) + 1)
       P      = left + center + right
       return P

    # if it is a '9' or if there is no one, we have to increment left :
    if center: center = '0'

    # handle the special case where every number on the left is a '9' :
    if left == '9' * (L / 2):
       P = '1' + '0' * (L - 1) + '1'
       return P

    # increment left :
    digits = list(left)
    pos = L / 2 - 1
    while digits[pos] == '9':
          digits[pos] =  '0'
          pos -= 1
    digits[pos] = str(int(digits[pos]) + 1)
    left  = ''.join(digits)
    right = left[::-1]
    P     = left + center + right
    return P


def main():
    T = int(raw_input().strip())
    for t in xrange(T):
        N = raw_input().strip()
        print process(N)

main()