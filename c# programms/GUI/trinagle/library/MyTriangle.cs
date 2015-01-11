using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Library_task
{
    public class MyTriangle
    {
        const double coefficient_error = 0.001;

        public MyPoint A { get; set; }
        public MyPoint B { get; set; }
        public MyPoint C { get; set; }

        public double halfPeriment;
        public double square;

        public MyTriangle(MyPoint a, MyPoint b, MyPoint c)
        {
            A = a;
            B = b;
            C = c;
            halfPeriment = (A.getDistance(B) + A.getDistance(C) + B.getDistance(C)) / 2;
            square = Math.Pow((halfPeriment * (halfPeriment - A.getDistance(B)) * (halfPeriment - A.getDistance(C)) * (halfPeriment - B.getDistance(C))), 0.5);
        }

        public bool MyPointBelong(MyPoint D)
        {

            bool result = false;
            // Найдем 3 треугольника, который получатся при добавлении точки.
            MyTriangle first = new MyTriangle(A, B, D);
            MyTriangle second = new MyTriangle(B, C, D);
            MyTriangle third = new MyTriangle(A, C, D);

            // А теперь немного заморочек со случаем, когда 3 точки лежат на 1 линии, и это уже фиговый треугольник.
            if (!first.is_correct() || !second.is_correct() || !third.is_correct())
            {
                if (!first.is_correct() && !D.is_between(A, B))
                    return false;
                if (!first.is_correct() && D.is_between(A, B))
                    return true;
                if (!second.is_correct() && !D.is_between(D, C))
                    return false;
                if (!second.is_correct() && D.is_between(D, C))
                    return true;
                if (!third.is_correct() && !D.is_between(A, C))
                    return false;
                if (!third.is_correct() && D.is_between(A, C))
                    return true;
            }

            double s1 = square;
            double s2 = first.square + second.square + third.square;
            double dif = s1 - s2;
            if (dif < 0)
                dif *= -1;
            // Ну если сумма площадей равна, то все хорошо
            if (dif < coefficient_error)
            {
                result = true;
            }

            return result;

        }

        private bool is_correct()
        {
            return ((A.getDistance(B) < B.getDistance(C) + A.getDistance(C) - coefficient_error) &&
                (A.getDistance(C) < A.getDistance(B) + B.getDistance(C) - coefficient_error) &&
                (B.getDistance(C) < A.getDistance(B) + A.getDistance(C) - coefficient_error));

        }

        public override string ToString()
        {
            return "Triniagle: " + A.ToString() + " " + B.ToString() + " " + C.ToString();
        }
    }
}
