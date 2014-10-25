using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Threading;

// класс для управления клиентскими запросами и ответами на них

namespace ConsoleApplication1
{
    class Parser
    {
        public void showText(object clientO)
        {

            
            Byte[] bytes = new Byte[256]; // Сначала мы получим массив байтов
            String query = null; // А потом переведем их в строку запроса
            TcpClient client = clientO as TcpClient; // Возьмем клиента, который к нам подключился
            NetworkStream stream = client.GetStream(); // И заберем с него байты

            int i;
            while ((i = stream.Read(bytes, 0, bytes.Length)) != 0) // И будем переводить его байты
            {

                string answerFromServer = "This is test!"; // Это ответ, которым мы пошлем клиенту

                query = System.Text.Encoding.UTF8.GetString(bytes, 0, i); // Переведем байты в строку
                Console.WriteLine("\nmessage:{0}", query);  // Выведем ее на экран
                string ipClient = ((IPEndPoint)client.Client.RemoteEndPoint).Address.ToString(); // Получим айпи адресс клиента
                Console.WriteLine("Client Ip Address is: {0}", ipClient); // Выведем его на экран

                
                // Вызвали базу пользователей
                UserBase userBase = new UserBase();
                userBase.loadFile(); // Загрузили имеющихся пользователей

                // убрал точку с запятой с запроса. Это необходимо для дальнейшей обрабоки
                query = query.Substring(0, query.Length - 1);

                

                // завели разделители, которыми будем парсить
                char[] charSeparatorsBlocks = new char[] { ';' };
                char[] charSeparatorsNameValue = new char[] { '=' };

                // получили массив блоков. То, что находится между ';'.
                string[] arrayBlocks = query.Split(charSeparatorsBlocks, StringSplitOptions.None);

                if (arrayBlocks.Length < 3) // Условия неверность запроса
                {
                    answerFromServer = "wrong query";
                }
                else
                {

                    // Получили массив из 2х элементов. В виде ключ = значение.
                    string[] arrayNameValueMethod = arrayBlocks[0].Split(charSeparatorsNameValue, StringSplitOptions.None);
                    string[] arrayNameValueEmail = arrayBlocks[1].Split(charSeparatorsNameValue, StringSplitOptions.None);
                    string[] arrayNameValuePassword = arrayBlocks[2].Split(charSeparatorsNameValue, StringSplitOptions.None);

                    // управление фукциями
                    switch (arrayNameValueMethod[1])
                    {
                        case "registration":
                            answerFromServer = "func=registration;";
                            userBase.addUser(arrayNameValueEmail[1], arrayNameValuePassword[1]);
                            userBase.saveFile();
                            answerFromServer += "regisresult=1;";
                            break;
                        case "entrace":
                            Console.WriteLine("entrace!");
                            answerFromServer = "func=entace;";
                            if (userBase.existUser(arrayNameValueEmail[1], arrayNameValuePassword[1]))
                                answerFromServer += "result=1;";
                            else
                                answerFromServer += "result=0;";
                            break;

                    }

                }
                




                // Эта штука посылает ответ клиенту по его айпи и порту 12 000 
                Socket soc = new Socket(SocketType.Stream, ProtocolType.Tcp);
                soc.Connect(ipClient, 12000);
                byte[] msg = Encoding.UTF8.GetBytes(answerFromServer);
                soc.Send(msg);
                soc.Shutdown(SocketShutdown.Both);
                soc.Close();    
            }
            client.Close();
        
        }
    }


}
