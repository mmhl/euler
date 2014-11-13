import qualified Data.Map as Map
import System.IO
import Data.Maybe

--insert numer of steps to map, return unmodified if value already exists 
collatzMapInsert :: (Integral a) => a -> a -> Map.Map a a  -> Map.Map a a
collatzMapInsert k v m = if Map.lookup k m == Nothing then (Map.insert k v m)
                         else m
--Lookup previously computed number of collatz steps in Map
collatzMapLookup :: (Integral a) => a -> Map.Map a a -> Maybe a
collatzMapLookup k m = Map.lookup k m

--Calculate how many steps of collatz sequence
collatzSteps :: (Integral a) => a -> a
collatzSteps 1 = 1
collatzSteps n = 1 + if odd n then collatzSteps $ 3*n+1
                else collatzSteps $ n `div` 2


collatz :: (Integral a) => a -> Map.Map a a -> a
collatz 1 _ = 1
collatz n m = if lookup == Nothing then dupa
             else fromJust $ lookup--collatzMapLookup n m
             where nextCollatz = if odd n then 3*n+1 else n `div` 2
                   lookup = collatzMapLookup n m
main = do
        putStrLn "Map"
        
