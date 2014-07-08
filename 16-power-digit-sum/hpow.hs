euler18 = sum . map(\x -> read [x] :: Int) $ show $ 2^1000
main = do (putStrLn.show) euler18



