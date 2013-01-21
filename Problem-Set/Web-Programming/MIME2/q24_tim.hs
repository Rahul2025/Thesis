import Data.Maybe (fromMaybe)
import qualified Data.Map as M
main :: IO ()
main = interact (unlines .  solve . parse . lines)
solve :: (M.Map String String , [String]) -> [String]
solve (m, fs) =
  map (\f -> fromMaybe "unknown" (ext f >>= flip M.lookup m)) fs
ext :: String -> Maybe String
ext f = if '.' `elem` f
  then Just $ reverse . fst . span (/= '.') $ reverse f
  else Nothing 
parse ::  [String] -> (M.Map String String, [String])
parse [] = error "premature end of input"
parse (topline:rest) = let [n,q] = map read $ words topline
                       in (M.fromList $ map (tuplify . words) $ take n rest,
                          map (head . words) $ take q $ drop n rest)
tuplify ::  (Show t) => [t] -> (t, t)
tuplify [x,y] = (x,y)  -- somewhat evil
tuplify other = error $ "expecting tuple but got " ++ show other
