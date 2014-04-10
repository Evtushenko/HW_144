let conv list f = [for x in list -> f(x)]

let convers = conv [1; 4; 76; 3] (fun x -> x * 2)

printf "%A" convers 