// List make list of x*x < 100
let genListSqr n =
    let rec genList' k =
        if k * k > n then
            []
        else
            k * k :: genList' (k + 1)

    genList' 1

printfn "%A" (genListSqr 100)