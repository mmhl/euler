from random import randint
from primes_common import exp_by_square
from primes_common import modulo



def is_prime_fermat(number): #Test the number for primality
	'''Ten algorytm probabilistyczny opiera sie na malym twierdzeniu Fermata
	jesli a^p = a (mod p) to jest to liczba prawdopodobnie pierwsza.
	dla wiekszej pewnosci mozna losowac liczby takie ze  a< p.
	Ten algorym ma pewien problem, mianowicie liczby Carmichaela, ktore moga
	dac zly wynik ( wynik a^(p-1)%p == 1 bedzie prawdziwy)'''
	p = number
	if p == 1:
		return False
	iterations = 10 #Just to be sure
	results = map(lambda x: modulo(x,p-1,p)== 1, [randint(1, p-1) for x in range(iterations+1)])
	return all(x == True for x in results)


def prime_fermat(start, stop=0):
	'''Returns next probably prime number'''
	if start <= 0:
		start = 1
	next_number = start
	while True:
		if is_prime_fermat(next_number) == True:
			yield next_number
		next_number += 1
		if next_number == stop:
			return
		



