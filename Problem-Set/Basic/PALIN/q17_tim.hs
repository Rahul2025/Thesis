module Main where
import qualified Data.ByteString.Lazy.Char8 as B
import System.IO
import Data.List
import Data.Char
-- The different kinds of numbers that we need to handle.  All
-- nines, a single digit, and numbers with an odd (resp. even)
-- number of digits.
data NumberType = AllNines
                | SingleDigit
                | OddDigits
                | EvenDigits
                  deriving (Eq)
-- Process the input. The first line is just the number of test
-- cases, and so is useless; skip it and pass the rest of the
-- input, as a list of lines, for further processing.
main :: IO ()
main = do input &lt;- B.getContents
          hSetBuffering stdout (BlockBuffering Nothing)
          mapM_ process_one_line $ tail $ B.lines input
-- Process a single line of (actual) input.
-- Extract the two numbers and pass them on to the function that
-- computes and prints the actual output.
process_one_line :: B.ByteString -> IO ()
process_one_line number  = let nextPalindrome = case numberType number of
                                 AllNines -> allNines number
                                 SingleDigit -> singleDigit number
                                 OddDigits -> oddDigits number
                                 _ -> evenDigits number  -- EvenDigits
                               in do
                             B.putStrLn nextPalindrome
-- Return the type of a number. Check for the following
-- properties, in this order:
-- 1. All digits are 9 : return AllNines
-- 2. Is just a single digit : return SingleDigit
-- 3. Has an odd number of digits : return OddDigits
-- 4. Has an even number of digits : return EvenDigits
numberType :: B.ByteString -> NumberType
numberType number
  | B.all (=='9') number = AllNines
  | length == 1 = SingleDigit
  | remainder == 1 = OddDigits
  | otherwise = EvenDigits
    where length = B.length number
          remainder = length `mod` 2
-- Return the next palindrome when every digit of the input number
-- is '9'. For this, just construct a string which is one longer
-- than the input number, starts and ends with '1', and has zeros
-- everywhere else (if there is any such place left).
allNines :: B.ByteString -> B.ByteString
allNines number = B.snoc prefix '1'
  where prefix = B.cons '1' zeros
        zeros = B.replicate numzeros '0'
        numzeros = length - 1
        length = B.length number
-- Return the next palindrome when the input number is just a
-- single digit, and is not '9'. For this, just return the next
-- number.
singleDigit :: B.ByteString -> B.ByteString
singleDigit number = B.pack $ show nextDigit
  where nextDigit = digit + 1
        Just(digit, _) = B.readInt number
-- Return the next palindrome when the input number has an odd
-- number of digits, except when it is all nines, or when it is a
-- single digit. These are handled by allNines and singleDigit,
-- respectively.
-- Split the input into : (prefix, middle digit,
-- suffix). If reverse(prefix) is greater than suffix, then the
-- answer is prefix ++ middle digit ++ reverse(prefix). Otherwise,
-- take this last number and starting from the middle digit,
-- increment outwards as follows:
-- If the middle digit is less than
-- 9, then increment the middle digit, and this is the answer.
-- If the middle digit is equal to 9, then make it zero and its
-- neighbors symmetrically zero as long as they are 9. Increment
-- the first pair of equidistant neighbors which are not 9, and
-- this is the answer.
oddDigits ::  B.ByteString -> B.ByteString
oddDigits number
  | greater reversePrefix suffix = B.append prefixPlus reversePrefix
  | middleValue &lt; 9 = B.append (B.snoc prefix (intToDigit $ middleValue + 1) ) reversePrefix
  | otherwise = let (nines, rest) = B.span (\a -> a == '9') reversePrefix
                    zeros = B.map (\_ -> '0') nines
                    Just(changed, unchanged) = B.uncons rest
                    nextDigit = intToDigit $ 1 + digitToInt changed
                    reversePrefix' = B.append (B.snoc zeros nextDigit) unchanged
                    prefix' = B.reverse reversePrefix'
                in B.append (B.snoc prefix' '0')  reversePrefix'
       where length = B.length number
             halfLength = (length - 1) `div` 2
             (prefix, rest) = B.splitAt halfLength number
             Just(middleDigit, suffix) = B.uncons rest
             reversePrefix = B.reverse prefix
             prefixPlus = B.snoc prefix middleDigit
             middleValue = (digitToInt middleDigit)
-- Given two ByteStrings a, b which represents two numbers with
-- the same number of digits, returns a > b.
greater :: B.ByteString -> B.ByteString -> Bool
greater first second
  | null remnant = False
  | otherwise = greaterFirst $ head remnant
    where remnant = dropWhile (\(a,b) -> a == b) $ B.zip first second
          greaterFirst (a,b) = (digitToInt a) > (digitToInt b) 
-- Return the next palindrome when the input number has an odd
-- number of digits, except when it is all nines. This is handled
-- by allNines.  Split the input into : (prefix, suffix). If
-- reverse(prefix) is greater than suffix, then the answer is
-- prefix ++ reverse(prefix). Otherwise, take this last number and
-- starting from the middle digit, increment outwards as follows:
-- If the middle two digits are less than 9, then increment the
-- middle digits, and this is the answer.  If the middle digits
-- are equal to 9, then make them zero and their neighbors
-- symmetrically zero as long as they are 9. Increment the first
-- pair of equidistant neighbors which are not 9, and this is the
-- answer.
evenDigits ::  B.ByteString -> B.ByteString
evenDigits number
  | greater reversePrefix suffix = B.append prefix reversePrefix
  | otherwise = let (nines, rest) = B.span (\a -> a == '9') reversePrefix
                    zeros = B.map (\_ -> '0') nines
                    Just(changed, unchanged) = B.uncons rest
                    nextDigit = intToDigit $ 1 + digitToInt changed
                    reversePrefix' = B.append (B.snoc zeros nextDigit) unchanged
                    prefix' = B.reverse reversePrefix'
                in B.append prefix' reversePrefix'
       where halfLength = (B.length number) `div` 2
             (prefix, suffix) = B.splitAt halfLength number
             reversePrefix = B.reverse prefix
