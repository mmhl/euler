factor :: (Num a, Integral a) => a -> [a]
factor x = factorize x 2
        where
        factorize 1 _ = []
        factorize x y = if x `mod` y == 0 then y : factorize (x `div` y) y
        else factorize x (succ y)

