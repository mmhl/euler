import math

factors = []
def factor(number):
	if number == 0:
		return [] 
	for i in xrange(2, number+1):
		if number % i == 0:
			factors.append(i)
			factor(number/i)
			break
	return factors

def main():
	number = 600851475143
	factors = factor(number)	
	print sorted(factors)	

if __name__ == "__main__":
	main()
