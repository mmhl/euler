import math
def is_first(number):
	if number % 2 == 0: return False
	result = True
	max_divisor = math.trunc(math.sqrt(number))
	for i in range(max_divisor, 1, -1):
		if number % i == 0:
			return False
		else: continue
	return True
#discover number'th prime
def prime_nth(number):
	primes = 1
	i = 2
	while True:
		i = i+1
		if is_first(i):
			primes = primes +1
			if(primes == number):
				break
	return i	
		

print prime_nth(10001)

