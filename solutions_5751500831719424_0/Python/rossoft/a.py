#!/usr/bin/python
import sys
import itertools
import os
import re
import string
import math

def all_runs(string):
    runs = []
    current = None
    run = ''
    for s in string:
        if current is None:
            run += s
            current = s
        else:
            if current == s:
                run += s
            else:
                runs.append(run)
                run = s
                current = s

    if run != '':
        runs.append(run)

    return runs

def solve_runs(runs):
    print runs
    num_packs = len(runs[0])
    total_cost = 0
    print runs
    for pack_index in xrange(num_packs):
        #find minimum length
        min_l = None
        for r in runs:
            #print r[pack_index]
            l = len(r[pack_index])
            if min_l is None:
                min_l = l
            else:
                min_l = min(l, min_l)
        #print

        for r in runs:
            l = len(r[pack_index])
            changes = l - min_l
            total_cost += changes


    return total_cost
def solver(params):
    strings = params['strings']
    if not is_possible(list(strings)):
        return "Fegla Won"

    new_strings = set(strings)
    if len(new_strings) == 1:
        #all equal already
        return 0

    #find all consecutive runs
    runs = []
    for s in strings:
        runs.append(all_runs(s))

    return solve_runs(runs)

def is_possible(strings):
    #remove all duplicate chars
    new_strings = set()
    for t in strings:
        for i in t:
            dup = i+i
            t = re.sub(dup, i, t)
        new_strings.add(t)

    return len(new_strings) == 1

def reader(in_file):
    parts = in_file.readline().strip().split(' ')
    n = int(parts[0])
    strings = []
    for i in xrange(n):
        strings.append(in_file.readline().strip())

    return {'strings': strings}


if __name__ == "__main__":
    from gcj import GCJ
    import os
    GCJ(reader, solver, os.getcwd(), "a").run()

