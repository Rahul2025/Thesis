{-# OPTIONS_GHC -O2 #-}
import qualified Data.ByteString.Lazy.Char8 as BS
import Data.Maybe
main :: IO()
main = do
  (l:ls) <- BS.lines `fmap` BS.getContents
  let n  = fst . fromJust $ BS.readInt l
  let ns = map (fst . fromJust . BS.readInt) $ take n ls
  putStr $ unlines $ map win ns
win :: Int -> String
win n
    |n `mod` 4 == 1 = "ALICE"
    |otherwise      = "BOB"

