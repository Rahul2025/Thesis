main = do
inptStr <- getLine
let y = read inptStr ::Int
pallindrome y
pallindrome x | x>0 = do
inptStr <- getLine
let y = read inptStr ::Int
putStrLn $ pall y 0
pallindrome (x-1)
| otherwise = putStr ""
pall y n | isPallindrome $ show y = show n ++ " " ++ show y
| otherwise = pall (y + rev y) (n+1)
isPallindrome y | y == reverse y = True
| otherwise = False
rev y = read (reverse $ show y) ::Int