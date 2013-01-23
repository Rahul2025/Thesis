import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
int :: B.ByteString -> Integer
int = fst . fromJust . B.readInteger
main::IO()
main = do
    line<-getLine
    stin <- B.getContents
    mapM_ (\line -> print . foldl1 gcd $ map int $ split line) (B.lines stin)
    where
    split s =
        let i = fromJust $ B.elemIndex ' ' s
            a = B.take i s
            b = B.drop (i+1) s
        in [a,b]