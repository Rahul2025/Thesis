import System.IO
import IO
import qualified Data.ByteString.Lazy.Char8 as S
chunk n = takeWhile (not.null) . map (take n) . iterate (drop n)
tail'= tail . S.lines
readInteger' x = case S.readInteger x of
                Nothing -> 1
                Just (k,t) -> k
readInt' x = case S.readInt x of
                Nothing -> 1
                Just (k,t) -> k
map'= map (show . algorithm . readInt')
-- Contest specific
facs = scanl (*) 1 [1..] :: [Integer]
fac :: Int -> Integer
fac n = facs !! n
algorithm :: Int -> Integer
algorithm x = (fac (2*(x-1)) `div` (fac (x)* fac (x-1))) `mod` 10000
-- Main
main = do
        hSetBuffering stdout (BlockBuffering (Just 4096))
        S.hGetContents stdin >>= hPutStrLn stdout . (unlines . map' . tail')
