module Main where
import Data.List
import System.IO
main = do
x <- readLn
sequence $ replicate x main'
hFlush stdout
main' = do
x <- getLine
let [a,b] = map (read.reverse) (words x)
print ((read.reverse.show $ a+b)::Integer)