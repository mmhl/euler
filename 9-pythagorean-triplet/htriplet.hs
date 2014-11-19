import Data.List
import Control.Applicative ((<$>))

main = do
        let (Just triplet) = find (\xs-> sum xs == 1000) $(\(m,n) -> sort [m^2-n^2, 2*m*n, m^2+n^2]) <$> [(m,n) | m <- [2,3..], n <- [1..pred m], odd(m-n)]
        putStrLn $ show $ product triplet
