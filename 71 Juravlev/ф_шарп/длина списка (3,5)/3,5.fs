// 3.5
// List length
let rec listLength list =
    match list with
    | [] -> 0
    | length:: tlist ->1 + listLength tlist

printfn "%A" (listLength [1; 2; 3; 4; 5])
