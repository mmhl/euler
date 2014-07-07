isPrime :: Int -> Bool
isPrime x = all (==False) $ map (divisible x) [2..floor.sqrt $ fromIntegral x]
        where
        divisible a b = mod a b == 0

euler10 = sum $ takeWhile(\x -> x < 2000000)[x | x<-[2..], isPrime x]
main = do
        (putStrLn . show ) euler10
