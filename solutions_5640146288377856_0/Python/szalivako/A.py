T = int(raw_input())
for ti in xrange(T):
	R, C, W = map(int, raw_input().split())
	ans = [[1], [2, 2], [3, 3, 3], [4, 3, 4, 4], [5, 4, 4, 5, 5], [6, 5, 4, 5, 6, 6], [7, 6, 5, 5, 6, 7, 7], [8, 8, 7, 6, 6, 7, 8, 8], [9, 8, 7, 5, 6, 7, 8, 8, 9, 9], [10, 9, 8, 7, 6, 7, 8, 9, 10, 10]]
	print 'Case #' + str(ti + 1) + ': ' + str(ans[C - 1][W - 1]) 