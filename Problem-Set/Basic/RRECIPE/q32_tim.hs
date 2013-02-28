import Control.Monad
import Control.Applicative
import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
main = readLn >>= flip replicateM_ (intf >>= putStrLn . intercalate " " . map show . f . tail)
f xs = map (`div` d) xs
	where d = foldl1' gcd xs
intf = unfoldr (B.readInteger . B.dropWhile isSpace) <$> B.getLine
