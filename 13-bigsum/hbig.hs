import Control.Applicative ((<$>), (<*>))

toIntegers :: [String] -> [Integer]
toIntegers = map read

main = do
        ints <- toIntegers.lines <$> getContents
        putStrLn $ take 10 $ show $ sum ints
