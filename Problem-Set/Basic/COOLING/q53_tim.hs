import Control.Monad
import qualified Data.ByteString.Char8 as B
import Data.Array
import Data.List
import Control.Applicative
import Data.Char
import Data.Function
main = readLn >>= flip replicateM_ (getLine >> sequence [sort <$> intf, sort <$> intf] >>= \[a, b] -> print $ f a b)
f g@(p:ps) h@(r:rs)	| p <= r = 1 + f ps rs
					| otherwise = f g rs
f _ _ = 0
intf = unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine