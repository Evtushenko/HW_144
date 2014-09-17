type Human (age:int, color:string, weight:int, height:int) = 
    member this.age = age
    member this.color = color
    member this.weight = weight
    member this.height = height
    abstract member sayJob : string -> unit 
    default u.sayJob (caption:string) = printfn "i am human"

type Student(age:int, color:string, weight:int, height:int) = 
    inherit Human(age, color, weight, height)
    override  x.sayJob caption = printfn "i am %s" caption 

let a = new Human (18, "green", 70, 180)
let b = new Student (19, "yellow", 60, 170)
a.sayJob "a"
b.sayJob "student"