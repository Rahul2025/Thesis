module Main where
import qualified Data.ByteString.Lazy.Char8 as B
main :: IO ()
main = do input <- B.getContents
          mapM_ putStrLn $ map process_one_line $ tail $ B.lines input
process_one_line :: B.ByteString -> String
process_one_line line = reverse_polish line [] [] -- formula, output, stack
-- Return the Reverse Polish Notation form of the formula given as input
reverse_polish :: B.ByteString -> String -> String -> String
reverse_polish      formula       output     stack
    | B.null formula = output
    | otherwise      =
       case first of
            '(' -> reverse_polish rest output stack
            ')' -> reverse_polish rest (output ++ [head stack]) $ tail stack
            '+' -> reverse_polish rest output ('+' : stack)
            '-' -> reverse_polish rest output ( '-' : stack)
            '/' -> reverse_polish rest output ( '/' : stack)
            '*' -> reverse_polish rest output ( '*' : stack)
            '^' -> reverse_polish rest output ( '^' : stack)
            _   -> reverse_polish rest (output ++ [first]) stack
       where first = B.head formula
             rest  = B.tail formula
