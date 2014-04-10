let rev list =
    let rec reverse acc list =
        match list with
        | [] -> acc
        | head::tail -> reverse (head::acc) tail 
    reverse [] list

let str = rev [1..5]

printfn "%A" str
