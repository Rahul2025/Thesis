module Main where
import Data.List
import System.IO
main = do
x <- hGetContents stdin
let inp = map ((`mod` 42).read) $ lines x
go inp
go [] = return ()
go xs = do
print $ length $ nub $ take 10 xs
go (drop 10 xs)