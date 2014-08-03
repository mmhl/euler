import Data.List
import Data.Maybe
lookupTable = [ (1, "one")
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
               ,(40, "fourty")
               ,(50, "fifty")
               ,(60, "sixty")
               ,(70, "seventy")
               ,(80, "eighty")
               ,(90, "ninety")
               ]

hundreds = "hundreds"
thousands = "thousands"

readTens :: Int -> Maybe String
readTens x 
        | x <= 0 && x >=100  = Nothing
        | lookupNumber x /= Nothing = lookupNumber x
        | otherwise = Just $ merge $ map (fromJust.lookupNumber) [tens x, ones x]
        where lookupNumber y = lookup y lookupTable
              tens x = x `div` 10 * 10
              ones x = x - tens x
              merge xs  = intercalate "-" xs
                
 
