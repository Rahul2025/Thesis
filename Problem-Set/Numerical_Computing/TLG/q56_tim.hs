import Control.Monad
import qualified Data.ByteString.Char8 as B
import Data.Array
import Data.List
import Control.Applicative
import Data.Char
import Data.Function
main = readLn >>= dushit 0 0 0 >>= putStrLn
dushit _ _ m 0 = return $ (if m < 0 then "2 " else "1 ") ++ show (abs m)
dushit i j m k = intf id >>= \[i', j'] -> dushit (i + i') (j + j') (maximumBy (compare `on` abs) [m, i - j]) (k - 1) 
intf f = B.getLine >>= return . f . unfoldr (B.readInt . B.dropWhile isSpace) 
