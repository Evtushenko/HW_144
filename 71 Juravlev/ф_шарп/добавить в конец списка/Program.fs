// List.Push end
let rec pushBack l n =
    match l with
    | [] -> n :: []
    | hd :: tl -> hd :: pushBack tl n

//printfn "%A" (pushBack [1; 2; 3] 4)
