main = do
input <- getContents
let lists = tail $ lines input
mapM_ print $ map countHoles lists
countHoles :: String -> Int
countHoles s = foldl (\acc x -> acc + hole x) 0 s
hole :: Char -> Int
hole c | c == 'B' = 2
| c `elem` "QROPAD" = 1
| otherwise = 0