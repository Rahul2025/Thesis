import qualified Data.ByteString.Char8 as BS
import Text.Printf
import qualified Data.List as L
bstoint arg = case BS.readInt arg of
    Nothing -> -1
    Just (x, _) -> x
bstointM :: BS.ByteString -> IO Int
bstointM arg = return $ bstoint arg 
readPoints 0 xs = return xs
readPoints n xs = do
    ligne <- BS.getLine
    let (x, rema) = case BS.readInt ligne of
            Just (number, remainder) -> (number, BS.drop 1 remainder)
            Nothing -> (0, BS.pack "0")
    let y = case BS.readInt rema of
                Just (number, _) -> number
                Nothing -> 0
    readPoints (n - 1) ( (x,y) : xs )
answer :: [(Int, Int)] -> Maybe (Int, Int) -> Double -> Double
answer []                 _                 acc = acc
answer ((x1,y1):pts)     Nothing            acc = answer pts (Just (x1,y1)) acc
answer ((x2,y2):pts)     (Just (x1,y1))     acc =
    answer pts (Just (x2, y2)) (acc + (sqrt (fromIntegral ( sqd (x1 - x2) + sqd (y1 - y2) ) ) ))
    where
        sqd a = a * a
loop 0 = return ()
loop t = do
    BS.getLine  -- eat blank line
    n <- BS.getLine >>= bstointM
    points <- readPoints n []
    let comparator (x1,y1) (x2, y2) = if x1 == x2 then compare y2 y1 else compare x1 x2
    let a = answer (L.sortBy comparator points) Nothing 0
    putStrLn (printf "%.2f" a)
    loop (t-1)
main = do
    t <- BS.getLine >>= bstointM
    loop t
