from math import *

def cmpute(r, t):
  #return sum(1+2*r + 4*j for j in xrange(t))
  #return 2*t**2 + (r*2-1)*t - 2*r - 1
  return t*(2*t + 2*r - 1)

#print cmpute(10000000000000000, 49)

def solve(r, t):
  a = 2
  b = (2*r-1)
  c = -t
  sol1 = (-b + (b**2.0-4*a*c)**0.5)/(2*a)
  sol2 = (-b - (b**2.0-4*a*c)**0.5)/(2*a)
  return int(floor(sol1))

T = int(raw_input())

for tc in xrange(1, T+1):
  r, t = map(int, raw_input().split())
  print "Case #%d: %s" % (tc, solve(r, t))
