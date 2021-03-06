import numpy as np
import math

class Case:
    def __init__(self):
        self.X = 0
        self.R = 0
        self.C = 0

    def solve(self):
        if self.X < 4:
            if (self.R * self.C) % self.X == 0 and \
               max(self.R, self.C) >= self.X and \
               min(self.R, self.C) >= (self.X / 2 + self.X % 2):
                return 'GABRIEL'
            return 'RICHARD'

        if self.X >= 7:
            return 'RICHARD'  # Richard can always choose a X-omino with a hole in it

        if self.X == 4:
            if (self.R * self.C) % self.X == 0 and \
               max(self.R, self.C) >= 4 and \
               min(self.R, self.C) >= 3:
                return 'GABRIEL'
            return 'RICHARD'

        if self.X == 5:
            if (self.R * self.C) % self.X == 0 and \
               max(self.R, self.C) >= 5 and \
               min(self.R, self.C) >= 4:
                return 'GABRIEL'
            return 'RICHARD'

        # Conjecture
        if self.X == 6:
            if (self.R * self.C) % self.X == 0 and \
               max(self.R, self.C) >= 6 and \
               min(self.R, self.C) >= 5:
                return 'GABRIEL'
            return 'RICHARD'




def read_case(file):
    case = Case()
    line = map(int, file.readline().split(' '))
    case.X = line[0]
    case.R = line[1]
    case.C = line[2]
    return case


def main():
    filename_in = 'D-large.in'
    filename_out = 'D-large.out'
    file_in = open(filename_in)
    file_out = open(filename_out, 'w')

    nb_case = int(file_in.readline())

    for k in range(1, nb_case + 1):
        case = read_case(file_in)
        to_write = 'Case #' + str(k) + ': ' + case.solve()
        print to_write
        file_out.write(to_write + '\n')

    file_out.close()


if __name__ == '__main__':
    main()