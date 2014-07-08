collatz :: Integer -> [Integer]
collatz 1 = [1]
collatz x = if odd x then x : collatz next_odd
	else x : collatz next_even
	where
	next_odd = 3*x + 1
	next_even = x `div` 2

