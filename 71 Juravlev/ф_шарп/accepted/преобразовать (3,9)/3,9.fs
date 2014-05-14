    let generator func list =
        let rec loop acc = function
        | [] -> acc
        | hd :: tl -> loop (func hd :: acc) tl
        List.rev (loop [] list)

    let newList = generator (fun x -> x*x*x) [1..5]
    printfn "%A" newList