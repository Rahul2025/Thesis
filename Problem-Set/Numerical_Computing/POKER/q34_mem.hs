import Data.List
import Data.Char
-- Haskell submission for codechef problem POKER
-- This is a terrible example of Haskell by a beginner
-- Author: Neill
--
-- To deal with aces being high or low, we generate all possible concrete hands
--   with each ace interpreted either high or low, and look for the best hand
--   from each concrete set of cards, then look for the max best hand.
--   This is very inefficient (when we've got 4 aces, we needn't generate 16
--   possible hands and go looking for whether we've a royal flush with each, etc)
type Rank = Int
type Suit = Char
type Card = (Rank, Suit)
readCard :: String -> (Rank, Suit)
readCard cs = let rc = cs !! 0
                  sc = cs !! 1
                  r  = rankCharToRank rc
              in (r, sc)
rankCharToRank :: Char -> Rank
rankCharToRank 'A' = 14
rankCharToRank 'K' = 13
rankCharToRank 'Q' = 12
rankCharToRank 'J' = 11
rankCharToRank 'T' = 10
rankCharToRank c =  digitToInt c
convert :: [String] -> [(Rank, Suit)]
convert xs = map readCard xs
cardToString :: Card -> String
cardToString (rank,suit) = [rankChar, suit]
  where
    rankChar = rankChars !! (rank-1) 
rankChars = "A23456789TJQKA"
data HandType = HighCard |
                Pair |
                TwoPairs |
                ThreeOfAKind  |
                Straight|
                Flush |
                FullHouse |
                FourOfAKind |
                StraightFlush |
                RoyalFlush deriving (Eq,Ord)
instance Show HandType where
  show RoyalFlush = "royal flush"
  show StraightFlush = "straight flush"
  show FourOfAKind = "four of a kind"
  show FullHouse = "full house"
  show Flush = "flush"
  show Straight = "straight"
  show ThreeOfAKind= "three of a kind"
  show TwoPairs= "two pairs"
  show Pair= "pair"
  show HighCard= "high card"
presentBestHand cs = show (findBestHandFromMany cs) ++  "     for cards: " ++ (show $map cardToString (reverse $ sort cs))
findBestHandFromOne cs = hand sortedCards
  where sortedCards = reverse $ sort cs
findBestHandFromMany cs = maximum $ map findBestHandFromOne (possibleCards cs)
-- It's critical they be sorted highest rank first, when passed to hand
hand :: [(Rank, Suit)] -> HandType
hand ((14,x1):(13,x2):(12,x3):(11,x4):(10,x5):[]) | x1==x2 && x2==x3 && x3==x4 && x4==x5  = RoyalFlush
hand ((n1,x1):(n2,x2):(n3,x3):(n4,x4):(n5,x5):[]) | areStraight (n1:n2:n3:n4:n5:[]) && x1==x2 && x2==x3 && x3==x4 && x4==x5  = StraightFlush
hand ((n1,_):(n2,_):(n3,_):(n4,_):(_,_):[])       | n1==n2 && n2==n3 && n3==n4 = FourOfAKind
hand ((_,_):(n1,_):(n2,_):(n3,_):(n4,_):[])       | n1==n2 && n2==n3 && n3==n4 = FourOfAKind
hand ((n1,_):(n2,_):(n3,_):(n4,_):(n5,_):[])      | n1==n2 && n2==n3 && n4==n5 || n1==n2 && n3==n4 && n4==n5 = FullHouse
hand ((_,x1):(_,x2):(_,x3):(_,x4):(_,x5):[])      | x1==x2 && x2==x3 && x3==x4 && x4==x5  = Flush
hand ((n1,_):(n2,_):(n3,_):(n4,_):(n5,_):[])      | areStraight (n1:n2:n3:n4:n5:[]) = Straight
hand ((n1,_):(n2,_):(n3,_):_:_:[])                | n1==n2 && n2==n3 = ThreeOfAKind
hand (_:_:(n1,_):(n2,_):(n3,_):[])                | n1==n2 && n2==n3 = ThreeOfAKind
hand (_:(n1,_):(n2,_):(n3,_):_:[])                | n1==n2 && n2==n3 = ThreeOfAKind
hand cs                                           | hasTwoPairs cs = TwoPairs
hand cs                                           | hasPair cs = Pair
hand cs                                                     = HighCard
hasTwoPairs :: [Card] -> Bool
hasPair :: [Card] -> Bool
-- broken - only works if we've already eliminated possibility of a three of a kind.
hasTwoPairs cs = 3 == (length $ nub ranks)
  where ranks = map fst cs
hasPair cs = 4 == (length $ nub ranks)
  where ranks = map fst cs
possibles :: [Int] -> [[Int]]
possibles [] = [[]]
possibles (14:xs) = map (1:) (possibles xs) ++  map (14:) (possibles xs)
possibles (n:xs) = map (n:) (possibles xs)
possibleCards :: [Card] -> [[Card]]
possibleCards cs = map reunite (possibles origRanks)
                   where reunite :: [Int] -> [Card]
                         origRanks = map fst cs
                         suits = map snd cs
                         reunite ranks = zipWith (\r s -> (r,s)) ranks suits 
-- TODO: don't let a straight go through the ace back to a king.
-- In any given set of ranks, ace should concretely be 14 or 1.
-- In that single concrete case the ace can't be adjacent to BOTH 2 and 13 (King).
-- TODO: allow this to work even if the ranks haven't already been sorted.
-- Currently, without sorting, the abs will allow 3,2,3,2,3
areStraight :: [Rank] -> Bool
areStraight [] = True
areStraight (x:[]) = True
areStraight (x:xs) = adjacent x (head xs) && areStraight xs
adjacent :: Int -> Int -> Bool
adjacent x y = 1 == abs (x-y)
-- some test data...
testData = [(["AH", "KH", "QH", "JH", "TH"], RoyalFlush),
  (["8H", "7H", "6H", "5H", "4H"], StraightFlush),
  (["AH", "2H", "3H", "4H", "5H"], StraightFlush),
  (["AH", "AS", "AC", "AD", "TH"], FourOfAKind),
  (["3H", "3S", "3C", "TH", "3D"], FourOfAKind),
  (["AS", "AC", "AD", "TH", "7H"], ThreeOfAKind),
  (["6H", "8S", "8C", "8D", "TH"], ThreeOfAKind),
  (["KH","9H", "8S", "8C", "8D"], ThreeOfAKind),
  (["3S", "4D", "5C", "6C", "7D"], Straight),
  (["AS", "KD", "QC", "JS", "TH"], Straight),
  (["7H", "AS", "AC", "AD", "7S"], FullHouse),
  (["3S", "3C", "JS", "JD", "3S"], FullHouse),
  (["3S", "7S", "JS", "KS", "9S"], Flush),
  (["4H", "3H", "2H", "AH", "KH"], Flush),
  (["3S", "7S", "JS", "KS", "9D"], HighCard),
  (["AH", "KH", "AS", "2H", "KS"], TwoPairs),
  (["2H", "KH", "2S", "7H", "KS"], TwoPairs),
  (["AH", "3S", "QH", "JH", "AS"], Pair),
  (["AH", "2S", "QH", "2H", "3S"], Pair),
  (["2H", "9H", "6H", "3H", "AS"], HighCard)]
demo = do putStrLn $ unlines  $ map (presentBestHand . convert . fst) testData
makeTestData = do
      putStrLn (show $ length testData)
      putStrLn $ unlines $ map (unwords . fst) testData
      putStrLn $ unlines $ map (show . snd) testData
main = do
  numTests <- (readLn::IO Int)
  processTest numTests
processTest 0 = return ()
processTest n = do
cardsStr <- getLine
let cards = map readCard (words cardsStr)
let answer = show $ findBestHandFromMany cards
putStrLn answer
-- putStrLn $ show cards
processTest (n-1)
