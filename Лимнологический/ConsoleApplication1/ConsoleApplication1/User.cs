using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class User
    {

        // коструктор
        public User(int idIn, string loginIn, string passwordIn)
        {
            id = idIn;
            login = loginIn;
            password = passwordIn;
        }
        // печать всех данных в консоль
        public void showData()
        {
            Console.WriteLine("id = {0}\nlogin = {1}\npassword = {2}", id, login, password);
        }
        // set - методы
        public void setId(int idIn)
        {
            id = idIn;
        }
        public void setLogin(string loginIn)
        {
            login = loginIn;
        }
        public void setPassword(string passwordIn)
        {
            password = passwordIn;
        }
        // get - методы
        public int getId()
        {
            return id;
        }
        public string getLogin()
        {
            return login;
        }
        public string getPassword()
        {
            return password;
        }

        // переменные, хранящие данные
        private int id;
        private string login;
        private string password;
    }
}
