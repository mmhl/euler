from random import randint
#def powmod(a, b, c): #a^b%c


def prime_fermat(number): #Test the number for primality
	'''Ten algorytm probabilistyczny opiera sie na malym twierdzeniu Fermata
	jesli a^p = a (mod p) to jest to liczba prawdopodobnie pierwsza.
	dla wiekszej pewnosci mozna losowac liczby takie ze  a< p.
	Ten algorym ma pewien problem, mianowicie liczby Carmichaela, ktore moga
	dac zly wynik ( wynik a^(p-1)%p == 1 bedzie prawdziwy)'''
	p = number
	if p == 1:
		return False
	iterations = 10 #Just to be sure
	candidates = [randint(1, p-1) for x in range(iterations+1)]
	results = map(lambda x: x**(p-1)%p == 1, [randint(1, p-1) for x in range(iterations+1)])
	return all(x == True for x in results)

	



