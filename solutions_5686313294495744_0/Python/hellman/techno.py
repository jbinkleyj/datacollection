#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys, math, random, operator
from string import ascii_lowercase
from string import ascii_uppercase
from fractions import Fraction, gcd
from decimal import Decimal, getcontext
from itertools import product, permutations, combinations
from Queue import Queue, PriorityQueue
from collections import deque, defaultdict, Counter
getcontext().prec = 100

MOD = 10**9 + 7
INF = float("+inf")

if sys.subversion[0] != "CPython":  # PyPy?
    raw_input = lambda: sys.stdin.readline().rstrip()
pr = lambda *args: sys.stdout.write(" ".join(str(x) for x in args) + "\n")
epr = lambda *args: sys.stderr.write(" ".join(str(x) for x in args) + "\n")
die = lambda *args: pr(*args) ^ exit(0)

read_str = raw_input
read_strs = lambda: raw_input().split()
read_int = lambda: int(raw_input())
read_ints = lambda: map(int, raw_input().split())
read_float = lambda: float(raw_input())
read_floats = lambda: map(float, raw_input().split())

"---------------------------------------------------------------"

def brute(lst):
    ans = 0
    for orig in product(range(2), repeat=len(lst)):
        ws1 = set()
        ws2 = set()
        for i, (w1, w2) in enumerate(lst):
            if orig[i]:
                ws1.add(w1)
                ws2.add(w2)
        for i, (w1, w2) in enumerate(lst):
            if not orig[i]:
                if w1 not in ws1 or w2 not in ws2:
                    break
        else:
            ans = max(ans, len(lst) - sum(orig))
    return ans


def solve(lst):
    return brute(lst)



T = read_int()
for t in xrange(1, T + 1):
    print >>sys.stderr, t, "/", T
    n = read_int()
    lst = [read_strs() for i in xrange(n)]
    solmy = solve(lst)
    if 1:
        solbrute = brute(lst)
        if solmy != solbrute:
            print "ERR", lst
            print solmy
            print solbrute
            quit()
    print "Case #%d: %s" % (t, solmy)
