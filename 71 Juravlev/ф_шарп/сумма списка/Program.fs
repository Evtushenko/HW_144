// List elements sum
let rec listSum list = 
    match list with
    | [] -> 0
    | sum :: tlist -> sum + listSum tlist

//printfn "%A" (listSum [1; 2; 3])
