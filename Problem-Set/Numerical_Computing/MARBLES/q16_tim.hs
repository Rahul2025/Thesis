choose _ 0 = 1
choose n k | k <= n-k   = choose (n-1) (k-1) * n `div` k
           | otherwise = choose n (n-k)
solve::Integer->Integer->Integer
solve n k = choose (n - 1) (n - k)
parse = parse0.map read.tail.words where
  parse0 [] = []
  parse0 (n:k:rest) = (n,k):parse0 rest
main=interact $ unlines.map (show.uncurry solve).parse
