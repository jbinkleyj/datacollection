#!/usr/bin/env python3

print('Case #1:')
for i in range(50):
  print('1' + ''.join(j*2 for j in '{:>07b}'.format(i)) + '1 3 4 5 6 7 8 9 10 11')

