import Data.List
main = do
	contents <- getContents
	let (no,restInput) = breakList 1 (words contents) []
	let result = (unwords (testcases (convertInt (unwords no)) restInput ) )-- only remaining part is to convert [String] into String
	putStr ((replace result ' ' '\n')++"\n")
--tested
-- all testcases done one-by-one
testcases::(Num a)=> a -> [String] -> [String]
testcases 0 _ = []
testcases t lst	| (elem m allelem) = "Yes" : (testcases (t-1) rest)
		|otherwise =  (testcase list m) : (testcases (t-1) rest)
		where
			n = (convertInt . head) lst
			m = (convertInt . head . tail) lst
			(banknotes,rest) = breakList n ((tail.tail) lst) []
			allelem = map convertInt banknotes
			list = dropAll m allelem
-- one test-case to check.
-- 'all' list contains notes smaller than m
testcase [] _ = "No"
testcase all@(banknote:banknotes) m  = if (compute all m []) > 0 then "Yes" else "No"
-- main logic of the program
compute [] no lst 	| sum lst == no = 1
			| otherwise = 0
compute (a:as) no lst 	| sum lst > no = 0
			| otherwise =
				 if (compute as (no-a) lst) == 1 then 1 else (compute as no lst) 
-- dumy function for sort in decreasing order
mysort x = sortBy xxx x
xxx a b  | a>b = LT
         | otherwise = GT
-- Converts an string x to corresponding no.
convertInt x = read x ::Int
-- this is tested working function!!
breakList:: (Num a) => a -> [b] -> [b] -> ([b],[b])
breakList 0 a b = (b,a)
breakList _ [] b = (b,[])
breakList no lst lst1 = breakList (no-1) (tail lst) (lst1 ++ [head lst])
-- it is better than computing both independently from drop and take.
-- %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
-- string character replacement
replace lst ch mod = foldr f_help [] lst
		where f_help x xs  	| (x==ch) = mod:xs
					| otherwise = x:xs
-- drops all element greater than m
dropAll::(Ord a)=> a -> [a] -> [a]
dropAll m lst = foldr (\x y-> if x>m then y else x:y)  [] lst
