import System.IO
import Control.Monad
import Data.Bits
main = readLn >>= (flip replicateM_ $ runTestCase)
runTestCase :: IO ()
runTestCase = liftM (map read . words) getLine >>= putStrLn . show . solve
solve :: [Int] -> Int
solve (n : a : b : []) = let ones = onesInSol n a b
							in sum (map (2 ^) [n - 1,n - 2..n - ones])
onesInSol :: Int -> Int -> Int -> Int
onesInSol n a b = let ones = numOnes a + numOnes b
					in if ones <= n then ones else 2 * n - ones
numOnes :: Int -> Int
numOnes a = foldl (\acc x -> if (a .&amp;. (1 `shiftL` x)) == 0
