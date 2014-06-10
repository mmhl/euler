prime_factors 1  _ = []
prime_factors x y =  if x `mod` y == 0 
	then y :  prime_factors (x `div` y) y
	else prime_factors x (succ y)