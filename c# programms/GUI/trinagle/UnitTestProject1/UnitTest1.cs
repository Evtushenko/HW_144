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
            MyPoint b = new MyPoint(4, 6);
            MyPoint c = new MyPoint(4, 0);

            MyPoint in_point = new MyPoint(3, 2);
            MyPoint ex_point = new MyPoint(8, 8);

            MyTriangle triangle = new MyTriangle(a,b,c);

            Assert.AreEqual(true, triangle.MyPointBelong(in_point), "internal point checking");
            Assert.AreEqual(false, triangle.MyPointBelong(ex_point), "external point checking");
        }
    }
}
