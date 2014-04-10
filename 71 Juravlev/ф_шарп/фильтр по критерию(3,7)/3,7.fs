// 3.7

let rec filter con list =
    match list with
    | [] -> []
    | hd::tl -> if (con hd) then hd::(filter con tl) else (filter con tl)

let list = [-2;-1;0;1;2] in
    printf "Filter: %A\n" (filter (fun x -> x > 0) list)
