using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication5
{
    public class myParallelogram
    {
        const double coefficient_error = 0.001;

        public MyPoint A { get; set; }
        public MyPoint B { get; set; }
        public MyPoint C { get; set; }
        public MyPoint D { get; set; }

        public myParallelogram(MyPoint a, MyPoint b, MyPoint c, MyPoint d)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }

        public bool isCorrect()
        {
            double ab = A.getDistance(B);
            double bc = B.getDistance(C);
            double cd = C.getDistance(D);
            double da = A.getDistance(D);

            double dif1 = ab - cd;
            double dif2 = bc - da;
            if (dif1 < 0)
                dif1 *= -1;
            if (dif2 < 0)
                dif2 *= -1;
            return dif1 < coefficient_error && dif2 < coefficient_error ? true : false;
        }
    }
}
