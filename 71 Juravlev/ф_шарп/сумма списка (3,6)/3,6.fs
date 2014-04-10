// 3.6
let len list =
let rec loop list acc =
match list with
|[] -> acc
|head::tail -> loop tail (acc + 1)
loop list 0

let str = len [1..1000000]
