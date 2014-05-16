
// this story based on http://algolist.manual.ru/maths/findroot/cubic.php

// изъ€ть из кортежа i-ый элемент
let cubic (first, _, _, _) = first
let square (_, second, _, _) = second
let linear (_, _, third, _) = third
let constant (_, _, _, fourth) = fourth


let calc (coefficients : float * float * float * float) = // принимает кортеж типа флот
        let a = cubic coefficients
        let b = (square coefficients) / a
        let c = (linear coefficients) / a
        let d = (constant coefficients) / a


        let mutable q = (b * b - 3.0 * c) / 9.0 // может мен€ть значение
        let mutable r = (b * (2.0 * b * b - 9.0 * c) + 27.0 * d) / 54.0
        let r2 = r * r
        let q3 = q * q * q
        let b' = b / 3.0


        if r2 < q3 then
            let t = acos (r/sqrt(q3))
            q <- -2.0 * sqrt(q)
            let x1 = q * cos (t/3.0) - b'
            let x2 = q * cos ((t + 2.0 * System.Math.PI)/3.0) - b'
            let x3 = q * cos ((t - 2.0 * System.Math.PI)/3.0) - b'
            (x1, x2, x3)
        else 
            if r < 0.0 then
                r <- -r
            let alpha = -((r + sqrt(r2 - q3)) ** (1.0/3.0))
            let mutable beta = 0.0
            if alpha <> 0.0 then
                beta <- q/alpha
            q <- alpha + beta
            r <- alpha - beta
            let x1 = q - b'
            let x2 = (-0.5) * q - b'
            let x3 = (sqrt(3.0) * 0.5 * abs(r))
            (x1, x2, x3) // итоговые корни

let coefficients= (1.0, -6.0, 11.0, -6.0) // коэффициенты 

printfn "%A" (calc coefficients) // ждем корни от (x-1)(x-2)(x-3)

