using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Пример использования get-set
// Пример вызова консруктора из коструктора при наследовании.
// Переопделеление и вызов родитесльского метода в дочернем классе.

namespace ConsoleApplication23
{

    public class Point
    {
        // статическое поле. Можно менять не без испрозований объекта!!!! Можно инициализировать в статическом конструкторе.
        public static int amount = 2;

        // кокструткор по умолчанию :)
        //public Point(): this(0,0) { }
        public Point(int x = 0, int y = 0) // можно умолчание задать и так.
        {
            X = x;
            Y = y;
        }
        public int X { get; private set;}
        public int Y { get; private set;}

        public override string ToString(){
            return "point: ("+X.ToString() + ";" + Y.ToString()+")";
        }

        public static Point Add(Point a, Point b)
        {
            Point result = new Point();
            result.X = a.X + b.X;
            result.Y = a.Y + b.Y;
            return result;
        }

        public virtual void say_dimension()
        {
            Console.WriteLine("Base: \"My demension is two!\"");
        }
    }

    public class Point_3D : Point {
        public int Z { get; private set; }
        public Point_3D() : base(0, 0) { Z = 0; }
        public Point_3D(int a = 0, int b = 0, int c = 0) : base(a,b) {Z = c;}

        public override void say_dimension()
        {
            base.say_dimension();
            Console.WriteLine("Dirived: \"My is 3 !!!\"");
        }

        public override string ToString()
        {
            return "point: (" + X.ToString() + ";" + Y.ToString() + ";" + Z.ToString() + ")";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("anonymus");
            var anon = new {a=1, b = "hello", c =3.5};
            Console.WriteLine(anon.a);
            Console.WriteLine(anon.b);
            Console.WriteLine(anon.c);
            Console.WriteLine("anonymus");


            Point a = new Point(1, 2);
            Point b = new Point(3, 5);
            Point sum = Point.Add(a, b);

            Point space = new Point_3D(1,2,3);
            //p.Y = 4;
            Console.WriteLine(sum);
            Point.amount = 3;
            Console.WriteLine(Point.amount);
            Console.WriteLine(new Point());
            Console.WriteLine("//////");
            Console.WriteLine(space);
            space.say_dimension();
        }
    }
}
