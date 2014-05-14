// ????? 20

let rec sum n = 
    if n < 10I then n
    else n % 10I + sum (n / 10I)

let rec factorial n =
    if n = 0 then 1I
    else 
        (2I) * factorial (n - 1)  


printfn "%A" (sum (factorial 1000))