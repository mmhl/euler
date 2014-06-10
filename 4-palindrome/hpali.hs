isPalindrome :: Int -> Bool
isPalindrome x 
	| show x == (reverse . show) x = True
	| otherwise = False

main = do
	let m = maximum $ filter isPalindrome [x*y | x <- [100..999], y <- [100..999], x*y `mod` 11 == 0]
	(putStrLn . show) m



