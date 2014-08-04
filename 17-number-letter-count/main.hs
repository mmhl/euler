import Data.List
import Data.Maybe
lookupTable = [ (0, "")
			   ,(1, "one")
               ,(2, "two")
               ,(3, "three")
               ,(4, "four")
               ,(5, "five")
               ,(6, "six")
               ,(7, "seven")
               ,(8, "eight")
               ,(9, "nine")
               ,(10, "ten")
               ,(11, "eleven")
               ,(12, "twelve")
               ,(13, "thirteen")
               ,(14, "fourteen")
               ,(15, "fifteen")
               ,(16, "sixteen")
               ,(17, "seventeen")
               ,(18, "eighteen")
               ,(19, "nineteen")
               ,(20, "twenty")
               ,(30, "thirty")
               ,(40, "forty")
               ,(50, "fifty")
               ,(60, "sixty")
               ,(70, "seventy")
               ,(80, "eighty")
               ,(90, "ninety")
               ]
scales = [ "million"
	      ,"thousand"
		  ,"" 
		 ]
		

writeNumber :: Int -> Maybe String
writeNumber x 
        | x <= 0 && x >=100  = Nothing
        | lookupNumber x /= Nothing = lookupNumber x
        | otherwise = Just $ merge $ map (fromJust.lookupNumber) [tens x, ones x]
        where lookupNumber y = lookup y lookupTable
              tens x = x `div` 10 * 10
              ones x = x - tens x
              merge xs  = intercalate "" xs

numberGroup :: Int -> [Int]
numberGroup 0 = []
numberGroup n =  (numberGroup $ n `div` 1000) ++ [(n `mod` 1000 )]

parseTriple :: Int -> String
parseTriple n = if hasHundred 
	then toString hundreds ++ "hundred" ++ if hasTens then "and" ++ (toString tens) else ""
	else (fromJust $ writeNumber tens)
	where
	toString x = fromJust $ writeNumber x
	hundreds = n `div` 100
	tens = n `mod` 100
	hasHundred = hundreds > 0
	hasTens = tens > 0

addScale :: [String] -> [String]
addScale xs = zipWith (++) xs neededScales
	where 
	neededScales = drop (length scales - length xs) scales
numberStr :: Int -> String
numberStr 0 = "zero"
numberStr x = concat $ addScale $ map parseTriple $ numberGroup x

euler17 = sum $ map (length.numberStr) [1..1000]
main = do putStrLn $ show euler17
