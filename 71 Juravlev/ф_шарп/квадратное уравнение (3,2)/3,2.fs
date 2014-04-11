let squareSolve a b c =
    let d: double = (b*b-4.0*c*a)
    let x1: double = ( (-b)-sqrt(d) ) / 2.0 
    let x2: double = ( (b)-sqrt(d) ) / 2.0  
    x1, x2;;
    


let a = 4.0
let b = 5.0
let c = 1.0
let result = squareSolve a b c
printf "%A" result