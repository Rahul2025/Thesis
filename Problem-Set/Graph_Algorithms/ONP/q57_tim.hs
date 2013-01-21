{- input: a fully parenthesized expression of single-character variables and
          arbitrary binary operators
   output: the expression in one possible postfix-notation
   e.g (1+(2*3)) -> 123*+
 -}
data Tree = Operator Char Tree Tree
          | Variable Char
readTree :: String -> (Tree, String)
readTree ('(':s) = let (l, o:t) = readTree s
                       (r, ')':u) = readTree t
                   in (Operator o l r, u)
readTree (v:s) = (Variable v, s)
postfix :: Tree -> String
postfix = flip postfix_intern ""
postfix_intern :: Tree -> String -> String
postfix_intern (Operator o l r) = (postfix_intern l) . (postfix_intern r) . (o:)
postfix_intern (Variable v) = (v:)
convert :: String -> String
convert = postfix . fst . readTree
convertMany :: Int -> IO ()
convertMany n = do
  if n > 0
     then do
            s <- getLine
            putStrLn $ convert s
            convertMany (n-1)
     else
         return ()
getInt :: IO Int
getInt = do s <- getLine
            return (read s :: Int)
main = do amount <- getInt
          convertMany amount
