import Data.List
import Data.Maybe
pyTriplets = map (\(m,n) -> sort [m^2 - n^2, 2*m*n, m^2+n^2]) mnPairs
	where
		mnPairs = [(m,n) | n <- [1,3..3000], m<- [n+1,n+3..3000]]

euler9 = (product.fromJust) (find(\x -> sum x== 1000)pyTriplets)

main = do print $ euler9 
