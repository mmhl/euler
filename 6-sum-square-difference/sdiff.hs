
squareDiff :: [Int] -> [Int] -> Int
squareDiff xs ys = squared_sum - sum_square 
	where
	sum_square = sum $ map (^2) xs
	squared_sum = (^2) $ (sum ys)
