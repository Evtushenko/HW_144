printfn "welcome to Wild World!\n\n"
// herb =1
// pred = 2

type Animals (hpI : int, damageI :int, defenseI : int, nameI :string, idI:int) = 
    member x.damage = damageI
    member x.defense = defenseI
    member x.name = nameI
    member x.health = hpI
    member x.classId = idI
    abstract member tellMeAboutYourself : string -> unit 
    default u.tellMeAboutYourself (caption) = printfn "nothing"


type Herbivorous (hp:int, damage :int, defense :int, name: string) =
    inherit Animals(hp, damage, defense, name, 1)

type Predators(hp:int, damage :int, defense :int, name: string) = 
    inherit Animals(hp, damage, defense, name, 2)

             
    member this.attackFood (feeder : Animals ) =
        printfn "we are fighting with the food now!"
        printfn "food stats:\nname:%A with damage:%A with defense:%A with hp:%A" feeder.name feeder.damage feeder.defense feeder.health
        printfn "our stats:\nname:%A with damage:%A with defense:%A with hp:%A" name damage defense hp
        if (hp + defense - feeder.damage > feeder.health + feeder.defense - damage)
            then
                printfn "we ate him!\n"
            else
                printfn "we died!\n"
    member this.attackRival (rival: Animals) =
        printfn "we are fighting with the rival now!"
        printfn "rival stats:\nname:%A with damage:%A with defense:%A with hp:%A" rival.name rival.damage rival.defense rival.health
        printfn "our stats:\nname:%A with damage:%A with defense:%A with hp:%A" name damage defense hp
        if (hp + defense - rival.damage > rival.health + rival.defense - damage)
            then
                printfn "we ate him!\n"
            else
                printfn "we died!\n"

    member this.fight (target : Animals) =
        if (target.classId = 1)
            then this.attackFood target
            else
                this.attackRival target
   

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
//tiger.tellMeAboutYourself ""
let sheep = new Sheep("white", 1, 0, "Dolly", "grass", 10)
//sheep.tellMeAboutYourself ""

let tiger2 = new Tiger("orange",11, 16, "Rick", "sheeps", 100)

tiger2.fight tiger
//tiger.attackRival tiger2
tiger2.fight sheep

printfn "%A" tiger.classId

// herbivorous = o?aaiyaiua
// predators = oeuieee
