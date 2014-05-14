// долго работает!!!!
    open System.Numerics 

    let isPrime (number : BigInteger) =
        match number  with
        | _ when number  > 3I && (number  % 2I = 0I || number  % 3I = 0I) -> false
        | _ ->
            let upperLimit = BigInteger(System.Math.Sqrt(float number )) + 1I
            let rec loop (d : BigInteger) (i : BigInteger) = 
                if d > upperLimit then 
                    true
                else
                    if number  % d = 0I then 
                        false
                    else
                        loop (d + i) i    
            loop 5I 2I // стартовое простое число и шаг
    
    printfn "%A" ([1I..10I] |> List.filter (fun x -> isPrime x) |> List.sum)