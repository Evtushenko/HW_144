// 3.6

// List elements sum
let sum list =
    let rec loop list acc=
        match list with
        |[] -> acc
        |head::tail -> loop tail (acc + head)
    loop list 0

let sp = sum [1..10000]

printfn "%A" sp
