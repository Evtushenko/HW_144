printfn "%A" "welcome to Wild World!"

type Animal = interface
    abstract SaySomething : unit -> unit
    abstract Color : string
    abstract Age: int
    abstract WhatIsYourFood: unit -> unit
end

let Cat color age food =
    { new Animal with
        member x.SaySomething() = printfn "Meow!" 
        member x.Color = color
        member x.Age = age
        member x.WhatIsYourFood() = printfn "My food is %s" food  }

let Dog color age food = 
    { new Animal with
        member x.SaySomething() = printfn "Wow!" 
        member x.Color = color
        member x.Age = age
        member x.WhatIsYourFood() = printfn "My food is %s" food  }

let kitty = Cat "black" 5 "mise and birds!"
printfn "\t\t\t\tCat!"
kitty.WhatIsYourFood()
kitty.SaySomething()
printfn "my age is %i" kitty.Age
printfn "my color is %s" kitty.Color


let snooppy = Dog "white" 7 "cats and breads!"
printfn "\t\t\t\tDog!"
kitty.WhatIsYourFood()
kitty.SaySomething()
printfn "my age is %i" kitty.Age
printfn "my color is %s" kitty.Color