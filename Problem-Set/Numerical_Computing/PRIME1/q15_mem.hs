{-# OPTIONS_GHC -O2 #-}
import Data.List
import Data.Array.Unboxed
main = do
    n <- fmap read getLine
    sequence_ $ intersperse (putStrLn "") $ replicate n $ do
        [m,n] <- fmap (map read . words) getLine
        putStr $ unlines $ map show $ primesFromTo m n 
primesFromTo a b
    = [2 | a < 3, b > 1] ++ [i | i <- [o,o+2..b], ar ! i]
  where
    o  = 3 `max` (a + fromEnum (even a))
    r  = floor.sqrt.fromIntegral $ b+1
    ar :: UArray Int Bool
    ar = accumArray (\a _-> False) True (o,b)
          [(i,()) | p <- [3,5..r]
                    , let q  = p*p
                          s  = 2*p
                          (n,x) = quotRem (o - q) s
                          q' = if  o <= q  then q
                               else  q + (n + signum x)*s
                    , i <- [q',q'+s..b] ]
