module Main where
import Data.List
main = do
	x &lt;- readLn
	sequence $ replicate x main'
main' = do
	x &lt;- readLn
	print (sol!!x)
sol = map sum $ subsequences $  map (5^) [1..]