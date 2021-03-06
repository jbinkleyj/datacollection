#!/usr/bin/env python

import sys
from heapq import heappop, heappush

def solve(senate):
    heap = []
    for party, count in senate.iteritems():
        heappush(heap, (-count, party))
    plan = []
    while heap:
        turn = ""
        count, party = heappop(heap)
        turn+= party
        count+= 1
        if count:
            heappush(heap, (count, party))
        if not heap:
            break
        if (len(heap) == 2) and (heap[0][0] == heap[1][0]):
            plan.append(turn)
            continue
        count, party = heappop(heap)
        turn+= party
        count+= 1
        if count:
            heappush(heap, (count, party))
        plan.append(turn)
    return plan


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for casenum in xrange(T):
        sys.stdin.readline()
        senate = dict()
        for party, count in enumerate(sys.stdin.readline().split(), ord('A')):
            senate[chr(party)] = int(count)
        answer = solve(senate)
        print "Case #%s:" % (casenum + 1), " ".join(answer)
