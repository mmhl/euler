toDigits :: Int -> [Int]
toDigits 0 = []
toDigits x = toDigits ( x `div` 10) ++ [x `mod` 10]

toDigitsReverse :: Int -> [Int]
toDigitsReverse 0 = []
toDigitsReverse x = x `mod` 10 : toDigitsReverse(x `div` 10)

isPalindrome :: Int -> Bool
isPalindrome x 
	| toDigits x == toDigitsReverse x = True
	| otherwise = False

main = do
	let m = maximum $ filter isPalindrome [x*y | x <- [100..999], y <- [100..999], x*y `mod` 11 == 0]
	(putStrLn . show) m



