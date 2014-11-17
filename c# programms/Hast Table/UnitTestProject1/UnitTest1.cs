using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ConsoleApplication19;

namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            MyHashTable ht = new MyHashTable();
            bool expect = true;
            Assert.AreEqual(expect, ht.add("one"), "successfully added");
            Assert.AreEqual(expect, ht.add("two"), "successfully added");
            Assert.AreEqual(expect, ht.add("three"), "successfully added");


            Assert.AreEqual(expect, ht.find("one"), "successfully found");
            Assert.AreEqual(expect, ht.find("two"), "successfully found");
            Assert.AreEqual(expect, ht.find("three"), "successfully found");

            Assert.AreEqual(expect, ht.delete("one"), "successfully removed");
            Assert.AreEqual(expect, ht.delete("two"), "successfully removed");
            Assert.AreEqual(expect, ht.delete("three"), "successfully removed");

            expect = false;

            Assert.AreEqual(expect, ht.find("one"), "successfully not found");
            Assert.AreEqual(expect, ht.find("two"), "successfully not found");
            Assert.AreEqual(expect, ht.find("three"), "successfully not found");
        }
    }
}
