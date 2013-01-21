---------
--Imports
---------
import Data.List(sort)
--------------------------------------
--Data, Type and instance declerations
--------------------------------------
--Type
type CValue = CardValue Int
--Data
data CardValue a = Number a | Ten | Jack | Queen | King | Ace
	deriving(Eq, Ord) 
data CardSuit = Heart | Spade | Clover | Diamond
	deriving(Eq)
data Card = Card {cval :: CValue, csuit :: CardSuit}
data Hand = Hand {hcards :: [Card], hcardsDist :: [(CValue, [CValue])]}
data HandCombination = RoyalFlush | StraightFlush | FourOfAKind | FullHouse | Flush | Straight | ThreeOfAKind | TwoPairs | Pair | HighCard
--Instance
instance Show HandCombination where
	show RoyalFlush = "royal flush"
	show StraightFlush = "straight flush"
	show FourOfAKind = "four of a kind"
	show FullHouse = "full house"
	show Flush = "flush"
	show Straight = "straight"
	show ThreeOfAKind = "three of a kind"
	show TwoPairs = "two pairs"
	show Pair = "pair"
	show HighCard = "high card"
instance Show Hand where
	show = show . evalHand
------
--Main
------
main = interact(poker)
----------------------
--High level functions
----------------------
poker :: String -> String
poker = unlines . map show . map evalHand . map parseHand . tail . lines
----------------
--Card functions
----------------
readSuit :: Char -> CardSuit
readSuit 'H' = Heart
readSuit 'D' = Diamond
readSuit 'S' = Spade
readSuit 'C' = Clover
readValue :: Char -> CValue
readValue 'A' = Ace
readValue 'K' = King
readValue 'Q' = Queen
readValue 'J' = Jack
readValue 'T' = Ten
readValue n = Number $ read [n]
prev :: CValue -> CValue
prev Ace = King
prev King = Queen
prev Queen = Jack
prev Jack = Ten
prev Ten = Number 9
prev (Number 2) = Ace
prev (Number n) = Number (n-1)
parseCard :: String -> Card
parseCard = cft . tfs
	where
		tfs :: String -> (CValue, CardSuit)
		tfs str = (readValue $ str !! 0, readSuit $ str !! 1)
		cft :: (CValue, CardSuit) -> Card
		cft (a, b) =  Card a b
cardToInt :: CValue -> Int
cardToInt (Number n) = n
cardToInt Ten = 10
cardToInt Jack = 11
cardToInt Queen = 12
cardToInt King = 13
cardToInt Ace = 14
----------------
--Hand functions
----------------
evalHandDist :: [Card] -> [(CValue, [CValue])]
evalHandDist xs = [(s, eval s xs) | s &lt;- options]
	where
		options :: [CValue]
		options =  [Ace, King, Queen, Jack, Ten] ++ [Number n | n &lt;- [2..9]]
		eval :: CValue -> [Card] -> [CValue]
		eval c cs = filter (==c) $ map cval cs
parseHand :: String -> Hand
parseHand = th . map parseCard . words
	where
		th :: [Card] -> Hand
		th cs = Hand cs $ evalHandDist cs
isStraight xs = (nums == [h, h+1, h+2, h+3, h+4]) || ((init nums == [h, h+1, h+2, h+3]) &amp;& last nums == 14)
	where
		h = head nums
		nums = map cardToInt $ sort xs
evalHand :: Hand -> HandCombination
evalHand hand
	| isSameSuit &amp;& (sort values) == [Ten, Jack, Queen, King, Ace] = RoyalFlush
	| isSameSuit &amp;& straight = StraightFlush
	| isSame 4 = FourOfAKind
	| isSame 3 &amp;& isSame 2 = FullHouse
	| isSameSuit = Flush
	| straight = Straight
	| isSame 3 = ThreeOfAKind
	| (length $ filter (==2) (map (length.snd) $ hcardsDist hand)) == 2 = TwoPairs
	| isSame 2 = Pair
	| otherwise = HighCard
		where
			values = map cval $ hcards hand
			suits = map csuit $ hcards hand
			isSameSuit = all (==(head suits)) suits
			isSame x = any ((==x).length.snd) $ hcardsDist hand
			straight = isStraight values
