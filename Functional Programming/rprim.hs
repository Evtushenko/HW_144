 {-целая часть от деления-}
{-ex integerDivision 7 5  -}
integerDivision1 :: Int -> Int -> Int -> Int
integerDivision1 a b c = 
    if a - b >= 0 then integerDivision1 (a - b) (b) (c + 1)
    else c
integerDivision :: Int -> Int -> Int 
integerDivision a b =
    integerDivision1 a b 0

{-отсаток от деления-}
{-ex residue 5 2-}
residue :: Int -> Int -> Int
residue a b  =
    a - b* (integerDivision a b)
    
    
{-взаимная простота Метод Эвклида-}   
rprim1 :: Int -> Int -> Int
rprim1 a b = 
    if a > b && b /=  0
        then 
            rprim1   (b) (residue a b)
        else
            if b == 0
                then a
                else 1
rprim2 :: Int -> Int -> Int
rprim2 a b = 
    if a > b 
        then rprim1 a b
        else rprim1 b a
        
rprim :: Int -> Int -> String
rprim a b = 
    if rprim2 a b == 1
        then "yes"
        else "no"
