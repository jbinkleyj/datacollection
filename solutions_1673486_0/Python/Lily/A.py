def password(a, b, p):
	A = int(a)
	B = int(b)

	P = []	# probabilities
	for x in p.split(' '):
		P.append(float(x))

	k = []	# expected keystrokes
	# i = each possible number of backspaces
	# except - backspace A times will never be better than both backspace 0 times/pressing enter right away, so don't calculate
	for i in range(A):
		s1 = i*2 + 1 + B - A 	#number of strokes if correct the first time
		s2 = i*2 + 2 + 2*B - A 	#number of strokes if incorrect the first time
		
		# if backspace i times, then first A - i letters must be correct for s1
		p1 = 1					# probabilty of correct the first time
		for j in range(A-i):
			p1 *= P[j]
		p2 = 1 - p1				# probability of incorrect the first time
		
		k.append(s1 * p1 + s2 *p2)
		
	# enter right away = number of keystrokes, times 1
	k.append(2 + B)

	return min(k)


f = open('A-small-attempt0.in', 'r')
T = int(f.readline())
for i in range(T):
	nums = f.readline().split(' ')
	A = int(nums[0])
	B = int(nums[1])
	P = f.readline()
	#print (A,B)
	print "Case #{}: {}".format(i+1, password(A,B,P))