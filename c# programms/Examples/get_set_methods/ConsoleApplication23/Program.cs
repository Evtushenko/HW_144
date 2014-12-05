using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication23
{

    public class Point
    {
        public Point() { }

        private int x;
        private int y;
        public int X
        {
            get { return x; }
            set { x = value; }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Point p = new Point();
            p.X = 5;
            Console.WriteLine(p.X);
        }
    }
}
