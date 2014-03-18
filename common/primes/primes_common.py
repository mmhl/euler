import math

def modulo(a,b,c):
	'''Very fast a^b%c'''
	x = 1
	y = a
	while b > 0:
		if(b%2 == 1):
			x = (x*y)%c
		y = (y*y)%c
		b >>= 1
	return x%c

def exp_by_square(a,b): #a^b
	if b == 0:
		return 1
	elif b == 1:
		return a
	else:
		if b & 1 == 0: #even
			return exp_by_square(a**2, b/2)
		else: #odd
			return a*exp_by_square(a**2, (b-1)/2)
