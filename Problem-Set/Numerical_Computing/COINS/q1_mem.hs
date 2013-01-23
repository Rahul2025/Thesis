{-# OPTIONS_GHC -O2 #-}
import Control.Applicative
import Control.Monad
import Data.IORef
import Data.Map
import qualified Data.Map as M
import Data.ByteString.Char8(ByteString)
import qualified Data.ByteString.Char8 as B
import Data.Maybe 
run m n
    | n == 0              = (0,m)
    | isJust lookup       = (fromJust lookup, m)
    | otherwise           =
        let (c1, m1) = run m  (div n 2)
            (c2, m2) = run m1 (div n 3)
            (c3, m3) = run m2 (div n 4)
            r = max n (c1 + c2 + c3)
        in  (r, M.insert n r m3)
    where lookup = M.lookup n m
main = do
    ms <- B.lines <$> B.getContents
    imap <- newIORef M.empty
    forM_ ms $ \m -> do
        im <- readIORef imap
        let Just (n,_)  = B.readInteger m
            (res, im') = run im n
        writeIORef imap im'
        print res
