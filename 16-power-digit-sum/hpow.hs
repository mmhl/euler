toDigits :: (Num a, Integral a) => a -> [a]
toDigits 0 = []
toDigits x = toDigits ( x `div` 10) ++ [x `mod` 10]

euler18 = sum $ toDigits $ 2^1000

main = do (putStrLn.show) euler18



