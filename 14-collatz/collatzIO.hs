import System.IO
import Data.List

collatz :: (Integral a) => a -> a
collatz 1 = 1
collatz n = if odd n then 1 + collatz (3*n+1) 
            else 1 + collatz(n `div` 2)

collatzSeq :: (Integral a) => a -> [a] 
collatzSeq 1 = [1]
collatzSeq n = if odd n then n : collatzSeq(3*n+1)
               else n : collatzSeq(n `div` 2)

main = do
        putStr "Input number to calculate Collatz sequence: "
        hFlush stdout
        number <- getLine 
        let steps = show.collatz $ read number 
        let result = "Collatz sequence for " ++ number ++ " has " ++ steps
        let list = map (show) $ collatzSeq $ read number
        let pretty_list = foldl (++) [] $ intersperse "->" list
        putStrLn result
        putStrLn pretty_list
