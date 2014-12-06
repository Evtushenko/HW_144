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

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;
            if (obj.GetType() != this.GetType())
                return false;
            
            return Equals((Point)obj);
        }

        public bool Equals(Point other) {
            return X == other.X && Y == other.Y;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Point point1 = new Point(1, 2);
            Point point2 = new Point(1, 2);
            Point point3 = new Point(3, 1);
            Console.WriteLine(point1);
            Console.WriteLine(point1.Equals(point2));
            Console.WriteLine(point1.Equals(point3));

        }
    }
}
