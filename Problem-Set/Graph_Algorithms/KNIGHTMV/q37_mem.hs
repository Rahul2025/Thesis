import System.IO
import Data.Char
import Control.Monad
main = readLn >>= flip replicateM_ (getLine >>= putStrLn . correctMove)
correctMove :: String -> String
correctMove (sf : sr : '-' : ef : er : []) = if (sf <= 'h' && ef <= 'h' &&
	sf >= 'a' && ef >= 'a' && sr >= '1' && sr <= '8' && er >= '1' && er <= '8')
		then if (legalMove (ord sf) (ord sr) (ord ef) (ord er))
							then "Yes" else "No"
		else "Error"
correctMove _ = "Error"
legalMove :: Int -> Int -> Int -> Int -> Bool
legalMove sf sr ef er = if (abs (er - sr) == 1 && abs (ef - sf) == 2) ||
							(abs (er - sr) == 2 && abs (ef - sf) == 1)
			then True else False
