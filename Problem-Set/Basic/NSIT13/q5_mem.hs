import Data.List 
main::IO() 
main = do 
  sequence_ $ take 10 $ repeat $ do 
    s &lt;- sequence $ take 10 $ repeat  getLine 
    putStrLn $ show $ solve $ map read s
solve :: [Int] -> Int 
solve x = (length.group.sort) $ map (`mod` 42) x
