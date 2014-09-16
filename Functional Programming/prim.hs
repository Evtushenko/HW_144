 {-цела¤ часть от делени¤-}
{-ex integerDivision 7 5  -}
integerDivision1 :: Int -> Int -> Int -> Int
integerDivision1 a b c = 
    if a - b >= 0 then integerDivision1 (a - b) (b) (c + 1)
    else c
integerDivision :: Int -> Int -> Int 
integerDivision a b =
    integerDivision1 a b 0

{-отсаток от делени¤-}
{-ex residue 5 2-}
residue :: Int -> Int -> Int
residue a b  =
    a - b* (integerDivision a b)

prime1 :: Int -> Int -> String
prime1 input divider =
    if input == divider then "yes"
        else
        if (residue input divider) == 0 then "no"
            else
            prime1 input (divider + 1)
prim :: Int -> String
prim value = 
    prime1 value 2