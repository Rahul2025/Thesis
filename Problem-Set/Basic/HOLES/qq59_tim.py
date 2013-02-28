#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
:File: holes_in_text_chef.py
:Author: luca
:Version: 1.0.0
:Date: 16/07/2012

file di test per codechef
"""
import sys

def ioit():
    """ iterator on sys.stdin because i'm lazy. """
    while True:
        riga = sys.stdin.readline()
        if not riga:
            break
        yield riga

if __name__ == "__main__":
    cin = ioit()
    for i in xrange(int(cin.next())):
        tot_holes = 0
        line = cin.next()
        for char in line:
            if char in ['A', 'D', 'Q', 'R', 'O', 'P']:
                tot_holes += 1
            elif char == 'B':
                tot_holes += 2
        print tot_holes

