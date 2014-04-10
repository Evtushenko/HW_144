let rec reverse str = 
    match str with
    |hd::tl -> reverse(tl) @ [hd]
    |[] -> []

let str1 = reverse [1..10]

printfn "%A" str1;