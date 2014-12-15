using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ConsoleApplication1;

namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            MyPoint a = new MyPoint(0, 0);
            MyPoint b = new MyPoint(0, 3);
            MyPoint c = new MyPoint(4, 3);
            MyPoint d = new MyPoint(4, 0);

            MyPoint e = new MyPoint(2, 2);

            myParallelogram parall = new myParallelogram(a, b, c, d);

            Assert.AreEqual(true, parall.isCorrect(), "correct data chelking");
            parall = new myParallelogram(a, b, e, d);
            Assert.AreEqual(false, parall.isCorrect(), "incorrect data chelking");
        }
    }
}
