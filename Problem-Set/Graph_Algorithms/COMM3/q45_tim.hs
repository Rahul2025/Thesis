import System.IO
import Control.Monad
main = readLn >>= flip replicateM_ runOneCase
runOneCase :: IO ()
runOneCase = do
	r <- readLn
	a <- liftM (map read . words) $ getLine
	b <- liftM (map read . words) $ getLine
	c <- liftM (map read . words) $ getLine
	putStrLn (if checkDists a b c r then "yes" else "no")
checkDists :: [Float] -> [Float] -> [Float] -> Integer -> Bool
checkDists a b c r = atLeastTwo (dist a b) (dist a c) (dist b c) r
dist :: [Float] -> [Float] -> Float
dist a b = sqrt ((a !! 0 - b !! 0) ^ 2 + (a !! 1 - b !! 1) ^ 2)
atLeastTwo :: Float -> Float -> Float -> Integer -> Bool
atLeastTwo a b c r = count True [a <= fr, b <= fr, c <= fr] >= 2
	where
		fr = fromInteger r + 0.01
		count v = foldl (\acc x -> if v == x then acc + 1 else acc) 0
