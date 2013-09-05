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

def triangle(num):
	return ((num)(num+1))/2




