import System.IO
import Control.Monad
main = readLn >>= (flip replicateM_  $ runCase)
runCase :: IO ()
runCase = do
	k <- readLn
	putStrLn $ reverse . take (((k - 1) `div` 25) + k + 1) $
					(concat $ replicate 4 "abcdefghijklmnopqrstuvwxyz")
