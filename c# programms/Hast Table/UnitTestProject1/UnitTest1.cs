using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
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

            List<string> words = new List<string>();
            words.Add("hello");
            words.Add("world");
            words.Add("once");
            words.Add("upon");
            words.Add("a");
            words.Add("time");
            MyHashTable ht = new MyHashTable(words);

            /*
        Console.WriteLine(ht.Remove(hello.GetHashCode()));
        Console.WriteLine(ht.Remove((hello + "111").GetHashCode()));
         * */

            Assert.AreEqual(6, ht.Count(), "successfully added");
            string hello = "hello";
            Assert.AreEqual(true, ht.ContainsKey(hello.GetHashCode()), "found after adding");
            Assert.AreEqual(false, ht.ContainsKey((hello+"1").GetHashCode()), "found after adding");
            Assert.AreEqual("hello", ht.TryFind(hello.GetHashCode()), "got after adding");
            Assert.AreEqual("hello", ht[hello.GetHashCode()], "got after adding by []");
            Assert.AreEqual(true, ht.Remove(hello.GetHashCode()), "successfully removed");
            Assert.AreEqual(false, ht.Remove((hello + "111").GetHashCode()), "success not removed");
        }
    }
}
