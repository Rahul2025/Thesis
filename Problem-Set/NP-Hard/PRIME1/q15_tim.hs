module Main where
import qualified Data.ByteString.Lazy.Char8 as B
import System.IO
import Data.List
-- Process the input. The first line is just the number of test
-- cases, and so is useless; skip it and pass the rest of the
-- input, as a list of lines, for further processing.
main :: IO ()
main = do input &lt;- B.getContents
          hSetBuffering stdout (BlockBuffering Nothing)
          mapM_ process_one_line $ tail $ B.lines input
-- Process a single line of (actual) input.
-- Extract the two numbers and pass them on to the function that
-- computes and prints the actual output.
process_one_line :: B.ByteString -> IO ()
process_one_line line  = computeAndPrint m n
   where Just(m, rest) = B.readInt line
	 Just(n, _) = B.readInt $ head $ B.words rest
         --[first,second] = words line
-- Compute a list of the primes between n and m.
-- Construct one big string of the entries in this list,
-- separated and ended by newlines. Print this string and a
-- newline.
--computeAndPrint :: Integer -> Integer -> IO()
computeAndPrint :: Int -> Int -> IO()
computeAndPrint m n = let primeList = case m of
                                           1 -> 2 : (takeWhile (&lt;= n) $ primesFrom 3)
                                           2 -> 2 : (takeWhile (&lt;= n) $ primesFrom 3)
                                           _ -> takeWhile (&lt;= n) $ primesFrom m
                          in do
                      B.putStrLn $ B.unlines $ map (B.pack . show) primeList 
primes    = 2: oddprimes
oddprimes = 3: sieve oddprimes 3 0
-- sieve (p:ps) x k is the set of all numbers n which belong to
-- [x+2, x+4, ...., p^2 -2] such that the first k odd primes do
-- not divide n
sieve (p:ps) x k
          = [n | n &lt;- [x+2,x+4..p*p-2]
                 , and [rem n p/=0 | p &lt;- take k oddprimes]]
            ++ sieve ps (p*p) (k+1)
primesFrom m   = sieve ps (m `div` 2 * 2 - 1) (length h)
    where
      (h,(_:ps)) = span (&lt;= (floor.sqrt.fromIntegral) m) primes
