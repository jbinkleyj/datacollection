#!/usr/bin/python

import sys
from lawn import *

if len(sys.argv) > 1:
    filename = sys.argv[1]
else:
    filename = "sample.in"

input_file = open(filename, "r")
output_file = open(filename.replace('in','out'), "w")
case_count = int(input_file.readline())
for i in range(case_count):
    result = process_case(parse_case(input_file))
    output_line = 'Case #%d: %s\n' % (i+1, result)
    print(output_line)
    output_file.writelines(output_line)

input_file.close()
output_file.close()