import Data.List (unfoldr)
main = do 
	input <- getContents 
	let cases = map parseInts $ init $ lines input 
	mapM_ print $ map countFib cases
parseInts :: String -> (Integer, Integer) 
parseInts s = ((read $ w !! 0), (read $ w !! 1)) 
			  where w = words s	
fibs = unfoldr (\(a,b) -> Just (a,(b,a+b))) (1,2)
countFib :: (Integer, Integer) -> Int 
countFib (a,b) = length $ dropWhile (< a) $ takeWhile (<= b) fibs
