using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace ConsoleApplication19
{

    // зададим какой-то интерфейс.
    // еще мы хотим оператор [] и конструктор от списка слов.
    public abstract class MyHashTableInterface
    {
        public abstract int Count();
        public abstract bool ContainsKey(int key);
        public abstract bool Remove(int key);
        public abstract string TryFind(int key);

    }


    // новый тип Слово - значение
    class KeyWord
    {
        public KeyWord(int k, string v)
        {
            key = k;
            word = v;
        }
        public int key { get; set; }
        public string word { get; set; }
    }


    // А теперь реализуем
    public class MyHashTable : MyHashTableInterface
    {
        private List<KeyWord> list;
        public MyHashTable(List<string> input)
        {
            list = new List<KeyWord>();
            foreach (var s in input)
            {
                list.Add(new KeyWord(s.GetHashCode(), s));
            }
        }

        public override int Count()
        {
            return list.Count;
        }

        public override bool ContainsKey(int key)
        {
            foreach (var one in list)
            {
                if (one.key == key)
                    return true;
            }
            return false;
        }

        public override bool Remove(int key)
        {
            if (!ContainsKey(key))
            {
                return false;
            }

            // нужно найти индекс
            int index = -1;
            int c = 0;
            foreach (var one in list)
            {
                if (one.key == key)
                {
                    index = c;
                }
                c++;
            }
            if (index != -1)
            {
                list.RemoveAt(index);
                return true;
            }
            return false;
        }

        public override string TryFind(int key)
        {
            foreach (var one in list)
            {
                if (one.key == key)
                {
                    return one.word;
                }
            }
            return null;
        }

        public string this[int index]
        {
            get
            {
                return TryFind(index);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("u rock!");
        }
    }
}
