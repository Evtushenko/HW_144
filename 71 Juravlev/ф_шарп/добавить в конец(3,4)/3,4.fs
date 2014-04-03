// 3.4
printfn "%A" "para obtener ardilla"

// List.Push_back 
let rec pushBack l n =
    match l with
    | [] -> n :: []
    | hd :: tl -> hd :: pushBack tl n

printfn "%A" (pushBack [1; 2; 3] 4)
