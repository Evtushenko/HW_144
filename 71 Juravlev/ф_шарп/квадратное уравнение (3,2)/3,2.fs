let squareSolve ( a: float) (b : float) (c : float) =
        let (d : float) = sqrt(b * b - 4.0 * a * c)
        let calcRoot d = (-b + d) / (2.0 * a)
        let x1 = calcRoot d
        let x2 = calcRoot -d
        (x1, x2)

let (x1, x2) = squareSolve 1.0 3.0 -4.0
printfn "%A" (x1, x2)