main::IO() 
main = do 
  t &lt;- getLine 
  sequence_ $ take (read t) $ repeat $ do 
    li &lt;- getLine 
    let (a,b) =  solve (read li :: Integer) 
    putStrLn $ show a ++ " " ++ show b
solve :: Integer -> (Int, Integer) 
solve x = if palindromeTest x then (0,x) else (a+1,b) 
  where (a,b) = solve (x + reverseDigit x)
palindromeTest :: Integer -> Bool 
palindromeTest num = pt [] [] num 
  where 
    pt [] [] 0 = True 
    pt (x:xs) (y:ys) 0 = (x == y) &amp;& pt xs ys 0 
    pt xs ys n = pt (xs++[b]) (b:ys) a where (a,b) = quotRem n 10
reverseDigit :: Integer -> Integer 
reverseDigit x = rd 0 x 
  where 
    rd y 0 = y 
    rd y z = rd (10*y+b) a where (a,b) = quotRem z 10
