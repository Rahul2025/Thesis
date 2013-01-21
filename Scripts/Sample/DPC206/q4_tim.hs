module Main where
import Data.List
main = do
x <- readLn
sequence $ replicate x main'
main' = do
x <- readLn
let (a,b) = go x
putStrLn $ (show a)++" "++(show b)
isPalindrome x = (reverse sx)==sx
where sx = show x
go n = head $ dropWhile (not.isPalindrome.snd) $ iterate (\(a,b) -> (a+1,next b)) (0,n)
next n = n + (read.reverse.show $ n)