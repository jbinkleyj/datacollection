__author__ = "Quy Doan"

import sys

input_file = sys.argv[1]
output_file = sys.argv[2]

with open(input_file,"r") as reader:
    with open(output_file, "w") as writer:
        '''Do stuffs'''
        num_of_test = int(reader.readline())
        for test in range(num_of_test):
            n = int(reader.readline())
            appear = [0 for i in range(2501)]
            for i in range(2*n-1):
                ls = map(int,reader.readline().split())
                for l in ls:
                    appear[l] += 1
            res = []
            for i in range(2501):
                if appear[i] % 2 == 1:
                    res.append(i)
            res = sorted(res)
            res = [str(x) for x in res]
            print " ".join(res)
            writer.write("Case #"+str(test+1)+": " + " ".join(res)+"\n")
