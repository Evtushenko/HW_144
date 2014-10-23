using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class UserBase
    {
        private List<User> userList = new List<User>();
        public UserBase()
        {
            amountUsers = 0;
        }

        public void loadFile()
        {
            amountUsers = 0;
            string line;
            System.IO.StreamReader file =
                new System.IO.StreamReader(@"C:\Users\stars_000\Desktop\iMess\allAcounts.txt");

            /*
            while ((line = file.ReadLine()) != null)
            {
                if (line.Length > 0)
                    Console.WriteLine("line={0}", line);
            }
             */


            while ((line = file.ReadLine()) != null)
            {
                if (line.Length > 0)
                {
                    // line - строка где 1 учетная запись

                    // убрали лишнюю точку с запятой
                    line = line.Substring(0, line.Length - 1);

                    // завели разделители
                    char[] charSeparatorsBlocks = new char[] { ';' };
                    char[] charSeparatorsNameValue = new char[] { '=' };
                    // получили массив блоков
                    string[] arrayBlocks = line.Split(charSeparatorsBlocks, StringSplitOptions.None);


                    string[] arrayNameValueId = arrayBlocks[0].Split(charSeparatorsNameValue, StringSplitOptions.None);
                    string[] arrayNameValueLogin = arrayBlocks[1].Split(charSeparatorsNameValue, StringSplitOptions.None);
                    string[] arrayNameValuePassword = arrayBlocks[2].Split(charSeparatorsNameValue, StringSplitOptions.None);

                    addUser(arrayNameValueLogin[1], arrayNameValuePassword[1]);
                }
            }
            file.Close();
        }

        public bool existUser(string log, string pas)
        {
            foreach (User one in userList)
            {
                if (one.getLogin() == log && one.getPassword() == pas)
                    return true;
            }
            return false;
        }

        // сохраняем всех пользователей в файл allAcounts.txt (перезаписываем)
        public void saveFile()
        {

            List<string> lines = new List<string>();
            // добавлять в массив строк нужно
            foreach (User one in userList)
            {
                string result = "";
                result += "id=";
                result += (one.getId()).ToString();
                result += ";";
                result += "login=";
                result += (one.getLogin()).ToString();
                result += ";";
                result += "password=";
                result += (one.getPassword()).ToString();
                result += ";";
                //result += "\n";
                lines.Add(result);
            }
            string[] slot = lines.ToArray();
            //Console.WriteLine(slot[0]);
            //Console.WriteLine(slot[1]);
            // System.IO.File file = new File
            System.IO.File.WriteAllLines(@"C:\Users\stars_000\Desktop\iMess\allAcounts.txt", slot);
        }


        private int amountUsers;

        public void addUser(string log, string pas)
        {
            User newguy = new User(amountUsers++, log, pas);
            userList.Add(newguy);
            // for ex only
            //saveFile();
        }
        public void addUser(int id, string log, string pas)
        {
            User newguy = new User(id, log, pas);
            userList.Add(newguy);
        }
    }
}
