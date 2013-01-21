module Main where
import Prelude hiding (lookup)
import Data.IntMap
import Data.Maybe
change' m 0 = (0, m)
change' m n | isJust (lookup n m) = (fromJust (lookup n m), m)
change' m n = let (c1, m') = change' m (n `div` 2)
                  (c2, m'') = change' m' (n `div` 3)
                  (c3, m''') = change' m'' (n `div` 4)
                  r = max (toInteger n) (c1 + c2 + c3)
              in (r, insert n r m''')
change = fst . change' empty
main = catch (do n &lt;- getLine
                 putStrLn $ show $ change (read n :: Int)
                 main)
             (\_ -> return ())
