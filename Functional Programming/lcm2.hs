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

{-простое число -}
{-ex prime 17 -}
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
    
{-сколько раз число делется на данное -}
{-ex amountDivisions 24 2 0  -}
amountDivisions :: Int -> Int -> Int -> Int 
amountDivisions dividend divider result =
    if residue dividend divider == 0 
        then amountDivisions (integerDivision dividend divider) divider (result + 1)
        else result

{-тупо максимум-}
{-ex max  1 2-}
max1 :: Int -> Int -> Int
max1 a b = 
    if a > b 
        then a
        else b

{-тупо минимум-}
{-ex min  1 2-}
min1 :: Int -> Int ->Int 
min1 a b = 
    if a < b 
        then a
        else b


lcm1 :: Int -> Int -> Int -> Int -> Int
lcm1 a b counter result = 
    if counter > (max1 a b)
        then result
        else 
            if (prim counter) == "no" 
                then lcm1 a b (counter + 1) result 
                else lcm1 a b (counter + 1) (result * counter^(max1 (amountDivisions a counter 0) (amountDivisions b counter 0) ))
                
lcm2 :: Int -> Int -> Int 
lcm2 a b =
    lcm1 a b 2 1
