using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Пример использования get-set

namespace ConsoleApplication23
{

    public class Point
    {
        public Point() {
            Y = 0;
        }

        public int Y { get; private  set;}

        // поле
        private int x;
        private int y;
        // свойство
        public int X
        {
            get { return x; }
            set { x = value; }
        }
        // метод
        public void setToOrigin()
        {
            X = 0;
            Y = 46;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Point p = new Point();
            p.X = 5;
            p.setToOrigin();
            //p.Y = 4;
            Console.WriteLine(p.X);
            Console.WriteLine(p.Y);
        }
    }
}
