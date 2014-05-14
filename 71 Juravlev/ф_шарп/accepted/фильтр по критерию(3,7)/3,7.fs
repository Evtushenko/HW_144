// 3.7

let rec filter list =
    match list with
    |head::tail -> if (head < 4) then [head] @ filter(tail) else filter(tail)
    |[] -> []

let example = filter[10; 5; 1; 2; 345; 1]

printfn "%A" example
