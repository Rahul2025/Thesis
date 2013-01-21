import Control.Monad
import Control.Applicative
import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
import Data.Maybe
main = map read . words <$> getLine >>= \[a, b, c] ->
	sequence [replicateM a readLn', replicateM b readLn', replicateM c readLn'] >>= \[a', b', c'] ->
	let t = govnobljadj a' b' c'
		in mapM_ print $ length t:t
readLn' = fst . fromJust . B.readInt <$> B.getLine
govnobljadj w1@(x:xs) w2@(y:ys) w3@(z:zs)	| x == y = x:govnobljadj xs ys w3
											| y == z = y:govnobljadj w1 ys zs
											| z == x = z:govnobljadj xs w2 zs
											| x < y && x < z = govnobljadj xs w2 w3
											| y < z && y < x = govnobljadj w1 ys w3
											| otherwise = govnobljadj w1 w2 zs
govnobljadj xs ys zs = xuitishja x y where (x:y:_) = sortBy (\x y -> if null x then GT else if null y then LT else EQ) [xs, ys, zs]
xuitishja w@(x:xs) z@(y:ys)	| x == y = x:xuitishja xs ys
							| x < y = xuitishja xs z
							| otherwise = xuitishja w ys
xuitishja _ _ = []
