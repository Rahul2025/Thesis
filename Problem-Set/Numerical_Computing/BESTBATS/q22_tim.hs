import Data.List
import Debug.Trace
c :: Int -> Int -> Int
n `c` k = product[1..n] `div` (product[1..n-k] * product [1..k])
solve :: [Int] -> Int -> Int
solve scores k = occurences splitAt scores `c` occurences splitAt (drop (length scores - k) (sort scores))
  where
    occurences a xs = length $ filter (== a) xs
    splitAt = (sort scores) !! (length scores - k)
solveLine caseNumber = do
  input &lt;- getLine
  let scores = map read $ words input
  input &lt;- getLine
  let k = read input
  let answer = solve scores k
  putStrLn $ show answer
main = do
  input &lt;- getLine
  let cases = read input
  mapM_ solveLine [1..cases]
