
import Data.Array
 
binarySearchArray :: (Ix i, Integral i, Ord e) => Array i e -> e -> Maybe i
binarySearchArray a x = binarySearch p (bounds a) where
  p m = x `compare` (a ! m)binarySearch :: Integral a => (a -> Ordering) -> (a, a) -> Maybe a
binarySearch p (low,high) 
  | high < low = Nothing
  | otherwise = 
      let mid = (low + high) `div` 2 in 
      case p mid of
        LT -> binarySearch p (low, mid-1)
        GT -> binarySearch p (mid+1, high)
        EQ -> Just mid
binarySearch :: Integral a => (a -> Ordering) -> (a, a) -> Maybe a
binarySearch p (low,high) 
  | high < low = Nothing
  | otherwise = 
      let mid = (low + high) `div` 2 in 
      case p mid of
        LT -> binarySearch p (low, mid-1)
        GT -> binarySearch p (mid+1, high)
        EQ -> Just mid        
