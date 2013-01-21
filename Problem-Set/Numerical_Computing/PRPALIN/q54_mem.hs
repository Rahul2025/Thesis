import Data.Char
import qualified Data.ByteString.Char8 as C
isPrime p = p > 1 &amp;& (all (\n -> p `mod` n /= 0 ) $ takeWhile (\n -> n*n &lt;= p) (2:[3,5..]))
nextP str
     |C.reverse next == next = next
     |otherwise =if odd len then npalo next next else npalo (C.pack (show (10^(len)))) (C.pack (show (10^len)))
       where next = incdigit str (len-1)
             len = C.length str
incdigit str 0 = (C.pack "10") `C.append` (C.tail str)
incdigit str pos = let digit = C.index str pos
                       strt = C.take pos str
                       end = C.drop (pos+1) str
                       rep = intToDigit ((digitToInt digit)+ 1)
                   in if (digit == '9') then incdigit (strt `C.append` (C.pack "0") `C.append` end) (pos-1) else (strt `C.append` (C.pack [rep]) `C.append` end)
cpy str pos = let digit = str `C.index` (pos-1)
                  strt = C.take pos str
                  end = C.drop (pos+1) str
              in  strt`C.append` (C.pack [digit]) `C.append` end
npalo str glob= let l = (C.length str) `div` 2
                    left = C.take l str
                    right = C.reverse left
                    new = left `C.append` (C.pack [(str `C.index` l)]) `C.append` right
                in if (new>glob) then new else npalo (incdigit str l ) glob
npale str glob = let l = (C.length str) `div` 2
                     left = C.take l str
                     right = C.reverse left
                     new = left `C.append` right
                 in if (new>glob) then new else npale ( cpy (incdigit str (l-1)) l) glob
conver bstring = read (C.unpack bstring)::Integer
nextPr str
     | str==C.reverse str &amp;& (isPrime ( conver str)) = str
     |otherwise =  nextPr (nextP str) 
main = do
       k&lt;-C.getLine
       C.putStrLn (nextPr  k)
