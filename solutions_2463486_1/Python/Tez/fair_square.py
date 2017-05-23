import sys
from bisect import bisect_left, bisect_right
# Roots of square palindromes that are also palindromes can be generated by 3 families.

def trivial_roots():
    yield ['1']
    yield ['2']
    yield ['3']


def binary_inc(bin_list):
    for i in xrange(len(bin_list)):
        if bin_list[-i - 1] == '0':
            bin_list[-i - 1] = '1'
            carry = False
            return bin_list
        elif bin_list[-i - 1] == '1':
            bin_list[-i - 1] = '0'
            carry = True
    return ['0'] + bin_list

def next_bin_perm(bin_list):
    # if bin_list == []:
    #     return ['0']
    if bin_list[:3] == ['1', '1', '1']:
        return ['0'] * (len(bin_list) + 1)
    elif bin_list.count('1') == 3 and bin_list[-1] == '0':
        # How many 0's are there at the end of the list?
        i = 0
        while bin_list[-i -1] == '0':
            i += 1
        return binary_inc(bin_list[:-i]) + (['0'] * i)
    else:
        return binary_inc(bin_list)


def binary_roots():
    # These are or the form 1[x][x]'1, where [x] is a string of 0s and 1s
    # with no more than three 1's, and [x]' = reverse[x]
    x = []
    while True:
        yield ['1'] + x + list(reversed(x)) + ['1']
        x = next_bin_perm(x)

# def shift_one_up(bin_list):
#     # Where's the '1'?
#     bin_list.index('1')
    
    

def ternary_roots():
    # These are of the form 1[x]y[x]'1, where [x] and [x]' are as for the binary roots,
    # and y is either 0, 1 or 2. If y = 2 then the string [x] has at most one 1, otherwise
    # if y < 2 then [x] has at most three 1s
    x = []
    while True:
        yield ['1'] + x + ['0'] + list(reversed(x)) + ['1']
        yield ['1'] + x + ['1'] + list(reversed(x)) + ['1']
        if x.count('1') <= 1:
            yield ['1'] + x + ['2'] + list(reversed(x)) + ['1']
        x = next_bin_perm(x)

def even_roots():
    # These are of the form 2[0]2 (when number of digits is even), or 2[0]x[0]2 (when 
    # the number of digits is odd). Here the expression [0] is a string of zero or more 0s,
    # and x is either 0 or 1
    x = []
    while True:
        yield ['2'] + x + x + ['2']
        yield ['2'] + x + ['0'] + x + ['2']
        yield ['2'] + x + ['1'] + x + ['2']
        x = x + ['0']

def all_roots():
    triv_gen = trivial_roots()
    bin_gen = binary_roots()
    tern_gen = ternary_roots()
    even_gen = even_roots()

    trivs_remain = True
    while trivs_remain:
        try:
            triv = triv_gen.next()
            yield triv
        except StopIteration:
            trivs_remain = False

    bin = bin_gen.next()
    tern = tern_gen.next()
    even = even_gen.next()
    while True:
        if min((len(bin), bin), (len(tern), tern), (len(even), even))[1] == bin:
            yield bin
            bin = bin_gen.next()
        elif min((len(bin), bin), (len(tern), tern), (len(even), even))[1] == tern:
            yield tern
            tern = tern_gen.next()
        elif min((len(bin), bin), (len(tern), tern), (len(even), even))[1] == even:
            yield even
            even = even_gen.next()

def all_squares():
    a_r = all_roots()
    root = a_r.next()
    roots = []
    squares = []
    while len(root) <= 51:
        root_long = long(''.join(root))
        roots.append(root_long)
        squares.append(root_long * root_long)
        root = a_r.next()
    return squares

if __name__ == '__main__':
    num_cases = int(sys.stdin.readline().strip())
    squares = all_squares()

    for c_n in range(num_cases):
        low, high = map(int, sys.stdin.readline().strip().split())
        i_low = bisect_left(squares, low)
        i_high = bisect_right(squares, high)
        print "Case #%d: %d" % (c_n + 1, i_high - i_low)