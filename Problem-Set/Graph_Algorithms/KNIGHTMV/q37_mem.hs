import System.IO
import Data.Char
import Control.Monad
main = readLn >>= flip replicateM_ (getLine >>= putStrLn . correctMove)
correctMove :: String -> String
correctMove (sf : sr : '-' : ef : er : []) = if (sf &lt;= 'h' &amp;& ef &lt;= 'h' &amp;&
	sf >= 'a' &amp;& ef >= 'a' &amp;& sr >= '1' &amp;& sr &lt;= '8' &amp;& er >= '1' &amp;& er &lt;= '8')
		then if (legalMove (ord sf) (ord sr) (ord ef) (ord er))
							then "Yes" else "No"
		else "Error"
correctMove _ = "Error"
legalMove :: Int -> Int -> Int -> Int -> Bool
legalMove sf sr ef er = if (abs (er - sr) == 1 &amp;& abs (ef - sf) == 2) ||
							(abs (er - sr) == 2 &amp;& abs (ef - sf) == 1)
			then True else False
