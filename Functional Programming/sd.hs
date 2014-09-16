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

amountDeviders:: Int -> Int -> Int -> Int
amountDeviders a start result = 
    if start > (integerDivision a 2)  + 1
        then result
        else
            if residue a start == 0
                then amountDeviders a  (start +1) (result + start)
                else amountDeviders a  (start +1) result
                
sd :: Int -> Int 
sd a = 
    amountDeviders a 2 0
                
    