module Main where
main = do
	t<-getLine
	let t1 = (read t)  :: Integer
	myLoop t1	
myOneOf _ [] = False
myOneOf y (x:xs)
	| y == x = True
	| otherwise = myOneOf y xs
rpn [] q _ = return q
rpn (x:xs) q s
	| (x:xs)==[] = return q
	| x=='(' = rpn xs q (x:s)
	| x==')' = checkTop xs q s
	| myOneOf x "+-*/%^" = rpn xs q (x:s)
	| otherwise = rpn xs (x:q) s
checkTop p q (x:xs)
	| x/='(' = checkTop p (x:q) xs
	| otherwise = rpn p q xs  
myLoop t  = do
	if (t > 0)
		then
		   do
		   str<-getLine
		   str1 <- rpn str [] []
		   putStrLn (reverse str1)
		   myLoop (t-1)
	      else
		   return ()