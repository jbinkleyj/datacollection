T=input()

def last(s) :
	if (len(s)==1) : return s
	else :
		return max(s[-1]+last(s[:-1]),last(s[:-1])+s[-1])
for test in xrange(1,T+1) :
	s=raw_input()
	print "Case #%d:"%test,last(s)


