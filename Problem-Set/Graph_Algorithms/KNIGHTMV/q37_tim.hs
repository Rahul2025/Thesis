main =
  interact (unlines . map (display . solve) . tail . lines)
solve :: String -> Maybe Bool
solve s = parse s >>= (return . isLegal)
isLegal ((x1,y1),(x2,y2)) = (dx,dy) `elem` [(1,2),(2,1)]
  where dx = abs (x1-x2)
        dy = abs (y1-y2)
type Pos = (Int,Int)
parse :: String -> Maybe (Pos,Pos)
parse [c1,r1,'-',c2,r2] =
  mapM parsePos [(c1,r1),(c2,r2)] >>= return . tuplify
  where tuplify [x,y] = (x,y)
parse other = Nothing
parsePos :: (Char, Char) -> Maybe Pos
parsePos (c,r)
  |    c `elem` ['a'..'h']
    &amp;& r `elem` ['1'..'8'] = Just (cToI, dToI)
  | otherwise                                  = Nothing
  where dToI = 1 + fromEnum r - fromEnum '1'
        cToI = 1 + fromEnum c - fromEnum 'a'
display (Just True) = "Yes"
display (Just False) = "No"
display Nothing = "Error"
