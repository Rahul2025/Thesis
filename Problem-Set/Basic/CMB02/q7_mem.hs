main::IO() 
main = do 
  t &lt;- getLine 
  sequence_ $ take (read t) $ repeat $ do 
    s &lt;- getLine 
    putStrLn $ show $ solve (1+read s :: Int)
solve :: Int -> Int 
solve x = if isPalindrome x then x else solve (x+1)
isPalindrome :: Int -> Bool 
isPalindrome n = ip [] [] n 
  where 
    ip [] [] 0 = True 
    ip (x:xs) (y:ys) 0 = x==y &amp;& ip xs ys 0 
    ip x y z = ip (x++[b]) (b:y) a where (a,b) = quotRem z 10
