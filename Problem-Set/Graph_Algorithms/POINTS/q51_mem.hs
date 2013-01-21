import Data.List (sortBy)
import Text.Printf (printf)
import qualified Data.ByteString.Char8 as BS
-- the standard sort is the slowest component
-- amended to deal with suspected trailing newline in input
-- (otherwise chop doesn't need a count)
main :: IO ()
main = BS.interact
  (BS.unlines . map solve . (\(n,ls) -> chop n parseOne ls) . firstSplit)
  where firstSplit bs = case BS.lines bs of
          (a:as) -> (readIntOrFail a, as)
          _ ->      error "No first line!"
type Problem = (Int, [Pos])
type Pos = (Int, Int)
parseOne :: [BS.ByteString] -> (Problem, [BS.ByteString])
parseOne (_:nstr:rest) =
  ((n, parsePoints $ take n rest), drop n rest)
  where
    parsePoints :: [BS.ByteString] -> [Pos]
    parsePoints = map (tuplify . map readIntOrFail . BS.words)
    n = readIntOrFail nstr
    tuplify [x,y] = (x,y)
    tuplify _ = error "Expected 2-elem array in tuplify"
parseOne other = error $ "bad chunk format: " ++ show other
readIntOrFail :: BS.ByteString -> Int
readIntOrFail x =
  maybe (error $ "bad "++show x) fst (BS.readInt x)
solve :: Problem -> BS.ByteString
solve (_, unsorted) =
  BS.pack $ printf "%.2f" $ sum $ zipWith dist sorted (drop 1 sorted)
    where sorted = sortBy sortRule unsorted
dist :: Pos -> Pos -> Double
dist (x1,y1) (x2,y2) = sqrt $ fromIntegral $ s dx + s dy
  where dx = x1 - x2
        dy = y1 - y2
        s a = a * a -- (much faster than a ^ 2)
chop :: Int -> ([a] -> (b,[a])) -> [a] -> [b]
chop 0 _ _ = []
chop _ _ [] = []
chop n f as = b : chop (n-1) f as'
  where (b, as') = f as
sortRule ::  Pos -> Pos -> Ordering
sortRule (x1,y1) (x2,y2) | x1 < x2   = LT
                         | x1 > x2   = GT
                         | y1 < y2   = GT
                         | y1 > y2   = LT
                         | otherwise = EQ
