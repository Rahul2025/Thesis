main = do
	input <- getContents
	let lists = map (tail . parseInts) $ tail $ lines input
	mapM_ putStrLn $ map (fmt . divBygcd) lists
parseInts :: String -> [Int]
parseInts s = map read (words s)
divBygcd :: [Int] -> [Int]
divBygcd l = map (`div` g) l
		   	 where g = lgcd l
lgcd :: [Int] -> Int
lgcd = foldl gcd 0
fmt :: [Int] -> String
fmt [] = ""
fmt (x:xs) = show x ++ " " ++ fmt xs
