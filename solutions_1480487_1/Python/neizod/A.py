for t in range(int(input())):
	n, *points = [int(v) for v in input().split()]
	x = sum(points)

	avg = x * 2 / n
	nomore = [p > avg for p in points]

	n = sum(not b for b in nomore)
	avg = (x * 2 - sum(p * b for p, b in zip(points, nomore))) / n
	nomore = [p > avg for p in points]

	need = [(avg - p) * 100 / x if not b else 0 for p, b in zip(points, nomore)]

	print('Case #{}: {}'.format(t+1, ' '.join('{:.6f}'.format(p) for p in need)))