using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication5
{
    public class MyPoint
    {
        const double coefficient_error = 0.001; // математические задачи всегда так должны быть.

        public MyPoint(int x, int y) { X = x; Y = y; }
        public int X { get; set; }
        public int Y { get; set; }

        public double getDistance(MyPoint o)
        {
            return Math.Pow((Math.Pow(X - o.X, 2) + Math.Pow(Y - o.Y, 2)), 0.5);
        }

        public bool is_between(MyPoint one, MyPoint two)
        {
            double exp1 = getDistance(one) + getDistance(two);
            double exp2 = one.getDistance(two);
            double exp3 = exp1 - exp2;
            if (exp3 < 0)
                exp3 *= -1;
            return exp3 < coefficient_error;
        }

        public override string ToString()
        {
            return "MyPoint: (" + X.ToString() + ";" + Y.ToString() + ")";
        }
    }
}
