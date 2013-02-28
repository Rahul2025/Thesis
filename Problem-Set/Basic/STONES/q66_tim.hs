import System.IO
import Control.Monad
main = readLn >>= flip replicateM_ runOneCase
runOneCase :: IO ()
runOneCase = do
	jewels <- getLine
	stones <- getLine
	putStrLn . show $ length $ filter (flip elem jewels) stones
