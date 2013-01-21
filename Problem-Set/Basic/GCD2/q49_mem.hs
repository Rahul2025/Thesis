{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE BangPatterns #-}
import qualified Data.ByteString.Lazy.Char8 as BS
import Data.Maybe (fromJust)
readInteger = fst . fromJust . BS.readInteger
body [] = []
body (a:b:xs) = gcd a b: body xs
main = putStr . unlines . map show . body . map readInteger . tail .
        BS.words =<< BS.getContents
--main = mapM_ (print . (\[a, b] -> gcd a b)) . map (map readInteger) .
        --map BS.words . tail . BS.lines =<< BS.getContents
