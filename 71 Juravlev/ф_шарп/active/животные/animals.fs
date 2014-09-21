printfn "welcome to Wild World!\n\n"

type Animals (hpI : int, damageI :int, defenseI : int, nameI :string) = 
    //let mutable hpII = hpI
    //let mutable defenseII = defenseI
    //let mutable damageII = damageI
    //let mutable nameII = nameI
    // дабл диспатч
    // val mutable myInt :int
    member x.damage = damageI
    member x.defense = defenseI
    member x.name = nameI
    member x.health = hpI
    abstract member tellMeAboutYourself : string -> unit 
    default u.tellMeAboutYourself (caption) = printfn "nothing"


type Herbivorous (hp:int, damage :int, defense :int, name: string) =
    inherit Animals(hp, damage, defense, name)

type Predators(hp:int, damage :int, defense :int, name: string) = 
    inherit Animals(hp, damage, defense, name)
    member this.attackFood (feeder : Herbivorous ) =
        printfn "we are fighting with the food now!"
        printfn "food stats:\nname:%A with damage:%A with defense:%A with hp:%A" feeder.name feeder.damage feeder.defense feeder.health
        printfn "our stats:\nname:%A with damage:%A with defense:%A with hp:%A" name damage defense hp
        if (hp + defense - feeder.damage > feeder.health + feeder.defense - damage)
            then
                printfn "we ate him!\n"
            else
                printfn "we died!\n"
    member this.attackRival (rival:Predators) =
        printfn "we are fighting with the rival now!"
        printfn "rival stats:\nname:%A with damage:%A with defense:%A with hp:%A" rival.name rival.damage rival.defense rival.health
        printfn "our stats:\nname:%A with damage:%A with defense:%A with hp:%A" name damage defense hp
        if (hp + defense - rival.damage > rival.health + rival.defense - damage)
            then
                printfn "we ate him!\n"
            else
                printfn "we died!\n"

type Tiger(color :string, defense : int, damage :int , name : string, foodName : string, hp:int) =
    inherit Predators(hp, damage, defense, name)
    member x.health = hp
    member x.damage = damage
    member x.defense = defense
    member x.color = color
    member x.name = name
    member x.foodName = foodName
    override  x.tellMeAboutYourself caption = printfn "I am tiger.\nMy name is  %A. \nMy skin is %A.\nI eat %A.\nBe ware! my damage is %A.\nDont even try! my defense is %A.\n\n" name color foodName damage defense

type Sheep (color :string, defense :int , damage:int , name : string, foodName : string , hp : int) =
    inherit Herbivorous(hp, damage, defense, name)
    //do hp <- 0
    member x.defense = defense
    member x.damage = damage
    member x.color = color
    member x.name = name
    member x.foodName = foodName
    override  x.tellMeAboutYourself caption = printfn "I am sheep. \nMy name is  %A.\nMy skin is %A.\nI eat %A.\nBe ware! my damage is %A.\nDont even try! my defense is %A.\n\n" name color foodName damage defense

let tiger = new Tiger("orange",10, 15, "James", "sheeps", 100)
tiger.tellMeAboutYourself ""
let sheep = new Sheep("white", 1, 0, "Dolly", "grass", 10)
sheep.tellMeAboutYourself ""

let tiger2 = new Tiger("orange",11, 16, "Rick", "sheeps", 100)

tiger2.attackRival tiger
tiger.attackRival tiger2
tiger2.attackFood sheep


// herbivorous = травоядные
// predators = хищники