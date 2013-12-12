import Data.Set
problem29 = Data.Set.size$Data.Set.fromList [x^y | x<-[2..100], y<-[2..100]]

