# coding: utf-8


import sys

def charge():
  f = open(sys.argv[1], 'r')
  f_out = open(sys.argv[1] + '_out', 'w')
  T = int(f.readline()) # the first line
  case = 1

  ### watch out for the large case
  lookup = [2**x for x in xrange(40)]

  for i in xrange(T):  
    P, Q = map(int,f.readline().split("/")) 
    output = 'Case #' + str(case) + ': '

    
    if not Q in lookup:
      output += "impossible"
   
    else: 
      x = 0
      while (1.0*P)/Q < 1.0/(2**x):
        x += 1
      output += str(x)

    f_out.write(output + '\n') 
    case += 1

if __name__ == "__main__":
  charge()
