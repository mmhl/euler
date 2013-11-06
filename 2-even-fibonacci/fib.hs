
fibs = 0 : 1 : zipWith(+) fibs(tail fibs) 
euler2 = sum[x | x <- takeWhile(<4000000)fibs, not(odd x)]
