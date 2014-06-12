isPrime :: Int -> Bool
isPrime 1 = False
isPrime 2 = True
isPrime x = all (==False) $ map (divisible x) [2..floor.sqrt $ fromIntegral x]
	where
	divisible a b = mod a b == 0

main = do
	(putStrLn . show ) ([x | x <-[2..], isPrime x] !! 10000)

