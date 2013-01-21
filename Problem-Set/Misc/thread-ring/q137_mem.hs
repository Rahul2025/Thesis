import Control.Monad
import Control.Concurrent
import System.Environment
import GHC.Conc

ring = 503

new ret l i = do
  r <- newEmptyMVar
  forkOnIO numCapabilities (thread ret i l r)
  return r


thread :: MVar () -> Int -> MVar Int -> MVar Int -> IO ()
thread ret i l r = go
  where go = do
          m <- takeMVar l
          if m > 1
              then (putMVar r $! m - 1) >> go
              else print i >> putMVar ret ()

main = do
  a <- newMVar . read . head =<< getArgs
  ret <- newEmptyMVar
  z <- foldM (new ret) a [2..ring]
  forkOnIO numCapabilities (thread ret 1 z a)
  takeMVar ret