using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
// нужно переопределить остальные методы для работы хэш таблицы

//MyHashTable - класс для работы со строковой хэштаблицей
// bool add(string word) - результат зависит от существования слова в списке
// public string find(string word) - аналогично
// public bool delete(string word) - аналогично
// public void readFromFile() - читаем из words.txt

// WordType - интерфейск оболочки вокруг стринга, который перегружает его хэш
// WordType1 и WordType2 - разные реализации хэш функций

namespace ConsoleApplication19
{
  
    public class WordType
    {
        protected const int numberSpan = 10000;
        protected string word;
        public WordType(string value)
         {
            word = value;
         }
        public override string ToString()
        {
            return word;
        }
    }
    
    public class WordType1 : WordType
    {
        public WordType1(string word) : base(word) { }
        public override int GetHashCode()
        {
            int result = 0;
            for (int i = 0; i < word.Length; i++)
            {
                string low = word.ToLower();
                Random rnd = new Random();
                result += (int)(low[i]) * (int)(low[i]);

            }
            return result % numberSpan;
        }

        public override bool Equals(Object obj)
        {
            if (obj == null || !(obj is WordType1))
                return false;
            else
                return word == ((WordType1)obj).word;
        }

        
    }

    public class WordType2 : WordType
    {
        public WordType2(string word) : base(word) { }
        public override int GetHashCode()
        {
            int result = 0;
            for (int i = 0; i < word.Length; i++)
            {
                string low = word.ToLower();
                Random rnd = new Random();
                result += (int)(low[i]) + (int)(low[i]);

            }
            return result % numberSpan;
        }

        public override bool Equals(Object obj)
        {
            if (obj == null || !(obj is WordType2))
                return false;
            else
                return word == ((WordType2)obj).word;
        }
    }

    public class MyHashTable
    {
        public Hashtable myHT;
        public MyHashTable()
        {
            myHT = new Hashtable();
        }
        public bool add(string word)
        {
            try
            {
                myHT.Add(new WordType1(word).GetHashCode(), word);
            }
            catch
            {
                return false;
            }
            return true;
        }
        public bool find(string word)
        {
            return (myHT[new WordType1(word).GetHashCode()] != null) ? true : false;
        }
        public bool delete(string word)
        {
            if (find(word)) {
                myHT.Remove(new WordType1(word).GetHashCode());
            }
            else 
            {
                return false;
            }
            return true;
        }
        static void Main(string[] args)
        {
           
        }
    }
}
