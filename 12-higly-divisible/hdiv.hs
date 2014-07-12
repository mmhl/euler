import Data.List
import Data.Maybe
factor :: (Num a, Integral a) => a -> [a]
factor x = factorize x 2
        where
        factorize 1 _ = []
        factorize x y = if x `mod` y == 0 then y : factorize (x `div` y) y
        else factorize x (succ y)

--When we have prime factors, each counting n_p times number of divisors equals (1+n_p)(1+n_q)(....)
divisorsNum :: (Num a, Eq a, Integral a) => a -> Int
divisorsNum x = product $ map(\x -> length x + 1) $ group $ factor x

triangles = map(\x -> (x*(x+1))`div`2) [1..]

euler12 = fromJust $ find(\x -> divisorsNum x > 500) triangles
main = do (putStrLn.show) euler12
