import Control.Monad
import Control.Applicative
import qualified Data.ByteString.Char8 as B
import Data.List
import Data.Char
import qualified Data.IntMap as I
main = getLine >> I.fromList . zip [1..] <$> intf >>= return . f >>= \r -> print (length r) >> mapM_ (putStrLn . intercalate " " . map show) r
f m = reverse $ fst $ foldl' g ([], m) (I.keys m) where
	g w@(l, m) k	| k `I.notMember` m = w
					| otherwise = (c':l, nm) where (c', nm) = c k m
	c k m	| k `I.notMember` m = ([k], m)
			| otherwise = (k:k', m') where (k', m') = c (m I.! k) (I.delete k m)			
intf = unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine
-- ne forM a replicateM         number game eee!!                   imeet smisl proteret podnos!
--       data xynta = gov Int | sr BOol
-- razobratjsa kak i cho i mozhno dalshe pizdovat
{-                              pr x = foldr (\p f -> x < p * p || rem x p /= 0 && f) True ps
f (x:xs) = g x xs where
	g xs [] = maximum xs
	g xs (ys:yss) = g [y + max i j | (y, (i, j)) <- zip ys $ zip ([0] ++ xs) (xs ++ [0])] yss
	-}
