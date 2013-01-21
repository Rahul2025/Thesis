module Main where
import Data.List (maximumBy)
import Data.Ord (comparing)
import Prelude hiding (round)
main :: IO ()
main = do
    (cases : xs) <- fmap (map read . words) getContents
    (putStrLn . tally . take cases . round 0) xs
round :: Int -> [Int] -> [Int]
round n (x : y : rest) = z : round z rest
    where
        z = x - y + n
tally :: [Int] -> String
tally xs = let x = maximumBy (comparing abs) xs in
    case x of
        _ | x > 0     -> "1 " ++ show x
          | otherwise -> "2 " ++ (show . abs) x
