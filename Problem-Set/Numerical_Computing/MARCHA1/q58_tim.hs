import Control.Monad
import qualified Data.ByteString.Char8 as B
import Data.Array
import Data.List
import Control.Applicative
import Data.Char
import Data.Function
main = readLn >>= flip replicateM_ (intf >>= \[sz, a] -> concat <$> replicateM sz intf >>= \d -> putStrLn $ if f a d then "Yes" else "No")
f 0 _ = True
f n (x:xs) | 0 < n = f n xs || f (n - x) xs
f _ _ = False
intf = unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine
