// 3.2

let sqr =
    let rec sqrfun elem num =
        if (elem < (num / 2)) then 
            if (elem*elem < num) then 
                (elem*elem)::(sqrfun (elem + 1) num) 
            else 
                (sqrfun (elem + 1) num)
        else []
    sqrfun 1     

printf "Sqr: %A" (sqr 10)
