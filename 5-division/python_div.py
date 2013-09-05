#!/bin/python
import math

def is_first(number):
	result = True
	max_divisor = math.trunc(math.sqrt(number))
	for i in range(max_divisor, 1, -1):
		if number % i == 0:
			return False
		else:
			continue
	return True

def primes(number):
	primes = []
	for i in range (2, number+1):
		if is_first(i):
			primes.append(i)
	return primes
	
def factor(number):
	factors = []
	if number == 1: return [1]	
	primes_list = primes(number)
	for p in primes_list:
		if p*p > number: break
		while number % p == 0:
			factors.append(p)
			number //= p
	if number > 1: factors.append(number)
	return factors 

result = 1
number_factors= []
range_primes = primes(20)
for number in range(2,20): #11 non included, 1 unnecessary
	number_factor = (number, factor(number))
	number_factors.append(number_factor)
print number_factors
#init dict
primes_dictionary = {k:v for k in range_primes for v in range(1)} # ugly but wtf
for single_prime in range_primes:
	for t in number_factors:
		single_prime_count = t[1].count(single_prime)
		print "@", t[0], " counted ",single_prime, " ", single_prime_count, " times" 
		if single_prime_count > primes_dictionary[single_prime]:
			print"Updating dic, was ", primes_dictionary[single_prime], " now will be ", single_prime_count
			primes_dictionary[single_prime] = single_prime_count

print primes_dictionary
