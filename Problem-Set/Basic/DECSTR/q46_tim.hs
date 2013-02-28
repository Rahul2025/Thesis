kWord a = let (n, m) = a `divMod` 25
              m' = if m == 0 then 0 else m + 1
          in reverse $ take (26*n+m') $ cycle ['a'..'z']
main = interact $ unlines.map (kWord.read).tail.lines
