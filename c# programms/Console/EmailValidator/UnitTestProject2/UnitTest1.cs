using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ConsoleApplication17;

namespace UnitTestProject2
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Program a = new Program();
            System.IO.StreamReader file = new System.IO.StreamReader(@"input.txt");
            String line = "";
            char[] charSeparator = new char[] { ' ' };
            while ((line = file.ReadLine()) != null)
            {
                if (line.Length > 0)
                {
                    string[] arrayNameMethod = line.Split(charSeparator, StringSplitOptions.None);
                    string email = arrayNameMethod[0];
                    bool expect = false;
                    if (arrayNameMethod[1] == "1")
                        expect = true;
                    Assert.AreEqual(expect, a.IsValidEmail(email), email+" "+arrayNameMethod[1]);
                }
            }
            file.Close();
        }
    }
}
