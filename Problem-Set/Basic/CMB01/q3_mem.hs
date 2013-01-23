main = do 
  t <- getLine 
  sequence_ $ take (read t) $ repeat $ do 
    li <- getLine 
    let [a,b] = words li 
        s = (read $ reverse a) + (read $ reverse b) :: Int 
    putStrLn $ dropWhile (=='0') $ reverse $ show s
