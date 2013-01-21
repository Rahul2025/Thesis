import Control.Monad
import Control.Applicative
import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
import qualified Data.IntSet as I
main = readLn >>= flip replicateM_ (intf >>= \[n, _] -> intf >>= \d -> putStr $ cute $ f $ I.toList $ (I.fromList [1..n]) I.\\ (I.fromList d))
f (x:y:zs) = (x:xs, y:ys) where (xs, ys) = f zs
f v = (v, [])
cute (schmo, ass) = intercalate " " (map show schmo) ++ "\n" ++ intercalate " " (map show ass) ++ "\n"
intf = unfoldr (B.readInt . B.dropWhile isSpace) &lt;$> B.getLine
