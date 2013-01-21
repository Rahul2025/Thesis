import Control.Monad
import Control.Applicative
import qualified Data.ByteString.Char8 as B
import Data.List
import Text.Printf
main = intf >>= \[a, b] -> print (f $ a - b)
f v	| 1 &lt; rem v 10 = v - 1
	| otherwise = v + 1
intf = unfoldr (B.readInt . B.dropWhile (== ' ')) <$> B.getLine
