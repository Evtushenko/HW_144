let filter func list =
        let rec loop acc = function
        | [] -> acc
        | hd :: tl ->
            match func hd with
            | true -> loop (hd :: acc) tl
            | false -> loop (acc) tl
        List.rev (loop [] list)

    let newList = filter (fun x -> x % 2 = 1) [1..5]
    printfn "%A" newList