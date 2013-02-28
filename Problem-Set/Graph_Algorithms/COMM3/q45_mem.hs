main =
  interact (unlines . map (display . solve) . chop parseOne . tail . lines)
data Problem = Problem Int [Pos] deriving (Show)
type Pos = (Int,Int)
parseOne :: [String] -> (Problem,[String])
parseOne (r:a:b:c:rest) = (Problem (read r) ps, rest)
  where
    ps :: [Pos]
    ps = map (tuplify . (map read . words)) [a,b,c]
    tuplify [x,y] = (x,y)
-- if any two of the three tranceivers are in range, then all can communicate
solve :: Problem -> Bool
solve (Problem r [a,b,c]) = length thoseInRange >= 2
  where thoseInRange = filter inRange pairs
        pairs        = [(a,b),(b,c),(a,c)]
        inRange (p1,p2) = dist p1 p2 <= fromIntegral r
        dist (x1,y1) (x2,y2) = sqrt $ fromIntegral (dx^2 + dy^2)
          where
            dx = x1 - x2
            dy = y1 - y2
display True = "yes"
display False = "no"
chop :: ([a] -> (b, [a])) -> [a] -> [b]
chop _ [] = []
chop f as = b : chop f as'
  where (b, as') = f as
