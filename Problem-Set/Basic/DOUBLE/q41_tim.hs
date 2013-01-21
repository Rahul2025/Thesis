{-# LANGUAGE BangPatterns #-}
module Main where
import Control.Monad
import qualified Data.ByteString.Char8 as B
readInt :: IO Int
readInt = do
    Just (n,_) <- fmap B.readInt B.getLine
    return n 
digitToChar :: Int -> Char
digitToChar n = toEnum (n + fromEnum '0')
digits :: Int -> [Int]
digits n = reverse $ digits' n
    where digits' n = let (d,m) = divMod n 10 in m:digits' d
printInt :: Int -> IO ()
printInt n = if n > 9
             then do
                printInt d
                putChar $ digitToChar m
             else
                putChar $ digitToChar m
    where (d,m) = divMod n 10
printInt2 :: Int -> IO ()
printInt2 n = if n == 0 then putChar '0' else f [] n
    where f !s 0 = putStr s
          f !s !n = let (d,m) = divMod n 10 in f (digitToChar m : s) d
main = do
    n <- readInt
    replicateM_ n $ do
        m <- readInt
        printInt2 $ (2*(m `div` 2))
        putChar '\n'
main2 = do
    forM [10000..21000] $ \n->do
        printInt2 n
        putChar '\n'
