import System.Random

fastPow :: (Integral a) => a -> a -> a
fastPow x 0 = 1
fastPow x 1 = x
fastPow x n = if even n then fastPow (x^2) (n `div` 2)
              else x * fastPow (x^2) ((n-1)`div`2)
--Returns s and d factors
getsd :: (Integral a, Ord a) => a -> (a, a)
getsd x = getsd_aux x 0
        where
        getsd_aux x s = if even x then getsd_aux (x `div` 2) (succ s)
                        else (s, x)



--Get an infinite list of random witnesses
--Args: (range lo, range hi) -> List of randoms
getA :: (Int, Int) -> IO [Int]
getA r = do 
                g <- getStdGen
                return (randomRs r g)


--Miller Rabin primality test. 
--TODO: Should we pass list of witnesses? Witness generation will be up to caller
millerRabin :: (Integral a) => a -> Int -> Bool
millerRabin x k
        | even x = False
        | otherwise = undefined
