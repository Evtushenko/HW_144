// List concatenation
let rec listCat l1 l2 =
    match l1 with
    | [] -> l2
    | hd :: tl -> hd :: listCat tl l2

//printfn "%A" (listCat [1; 2; 3] [4; 5])
