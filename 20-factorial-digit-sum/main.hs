euler20 = sum $ map(\x -> read[x] :: Int) $ show$product [1..100]
main = do (putStrLn.show) euler20
