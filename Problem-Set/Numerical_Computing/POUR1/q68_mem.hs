main :: IO ()
main = do
	(t:input) &lt;- lines `fmap` getContents
	let cases = makeCase [ readInt x | x &lt;- input ]
	let output = unlines [ show( solve x ) | x &lt;- cases ]
	putStr output
readInt :: String -> Int
readInt = read	
makeCase :: [Int] -> [(Int, Int, Int)]
makeCase (a:b:c:[]) = [(a, b, c)]
makeCase (a:b:c:xs) = (a, b, c):( makeCase xs )
solve :: (Int, Int, Int) -> Int
solve (a, b, c)
	| a &lt; c &amp;& b &lt; c = -1
	| c `mod` g /= 0 = -1
	| otherwise = minimum [ pours (x0 + k * (b `div` g)) (y0 - k * (a `div` g)) a b c, pours (x0 + (k + i) * (b `div` g)) (y0 - (k + i) * (a `div` g)) a b c ]
	where
		g = gcd a b
		(xG, yG) = euclid a b
		(x0, y0) = ((c `div` g) * xG, (c `div` g) * yG)
		(k, i) = getK x0 y0 a b g
getK :: Int -> Int -> Int -> Int -> Int -> (Int, Int)
getK x y a b g
	| x > y = (-(x `div` (b `div` g)), -1)
	| otherwise = (y `div` (a `div` g), 1)
euclid :: Int -> Int -> (Int, Int)
euclid a b
	| a `mod` b == 0 = (0, 1)
	| otherwise = (y, x - (a `div` b) * y)
	where
		(x, y) = euclid b (a `mod` b)
pours :: Int -> Int -> Int -> Int -> Int -> Int
pours 0 1 _ _ _ = 1
pours 0 y _ _ _ = 2 * y
pours 1 0 _ _ _ = 1
pours x 0 _ _ _ = 2 * x		
pours x y a b c
	| x > y = 2 * (x + out x a b c)
	| otherwise = 2 * (y + out y b a c)
out :: Int -> Int -> Int -> Int -> Int
out x a b c
	| a &lt; c &amp;& ((a * x) `mod` b) == c = (a * x) `div` b
	| otherwise = (a * x - c - 1) `div` b
