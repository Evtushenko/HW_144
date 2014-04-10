// 3.6

// List elements sum
let rec listSum l = 
    match l with
    | [] -> 0
    | hd :: tl -> hd + listSum tl

printfn "%A" (listSum [1; 2; 3])
