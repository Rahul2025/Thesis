main::IO() 
main = do 
  t <- getLine 
  sequence_ $ take (read t) $ repeat $ do 
    s <- getLine 
    let [str, prt] = words s 
    putStrLn $ if isSublist str prt then "1\n" else "0\n"
isSublist :: (Eq a) => [a] -> [a] -> Bool 
isSublist lis patt = isSublist' lis  patt []
isSublist' :: (Eq a) => [a] -> [a] -> [[a]] -> Bool 
isSublist' [] _ _ = False 
isSublist' (x:xs) patt patts = if elem [] newPatts then True else isSublist'  xs patt newPatts 
  where newPatts = map tail $ filter (\m -> head m == x)  (patt:patts)
