using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace ConsoleApplication1
{
    class Parser
    {
        public void showText(object clientO)
        {

            
            Byte[] bytes = new Byte[256];
            String data = null;
            TcpClient client = clientO as TcpClient;
            NetworkStream stream = client.GetStream();

            int i;
            while ((i = stream.Read(bytes, 0, bytes.Length)) != 0)
            {

                string answerFromServer = "This is test!";

                data = System.Text.Encoding.ASCII.GetString(bytes, 0, i);
                Console.WriteLine("\nmessage:{0}",data );
                string ipClient = ((IPEndPoint)client.Client.RemoteEndPoint).Address.ToString();
                Console.WriteLine("Client Ip Address is: {0}", ipClient);

                /*
                // здесь будет парсер
                UserBase userBase = new UserBase();
                userBase.loadFile();

                // убрал точку с запятой
                string query = data;
                query = query.Substring(0, query.Length - 1);
                Console.WriteLine(query);

                

                // завели разделители
                char[] charSeparatorsBlocks = new char[] { ';' };
                char[] charSeparatorsNameValue = new char[] { '=' };

                // получили массив блоков
                string[] arrayBlocks = query.Split(charSeparatorsBlocks, StringSplitOptions.None);
                
                // имя метода
                string[] arrayNameValueMethod = arrayBlocks[0].Split(charSeparatorsNameValue, StringSplitOptions.None);
                string[] arrayNameValueLogin = arrayBlocks[1].Split(charSeparatorsNameValue, StringSplitOptions.None);
                string[] arrayNameValuePassword = arrayBlocks[2].Split(charSeparatorsNameValue, StringSplitOptions.None);
                
                if (arrayNameValueMethod[1] == "registration")
                {
                    userBase.addUser(arrayNameValueLogin[1], arrayNameValuePassword[1]);
                    userBase.saveFile();
                    answerFromServer = "func=registration;result=1";
                }
                if (arrayNameValueMethod[1] == "entrace")
                {
                    Console.WriteLine("entrace!");
                    
                    if (userBase.existUser(arrayNameValueLogin[1], arrayNameValuePassword[1]))
                        answerFromServer = "func=entace;result=1";
                    else
                        answerFromServer = "func=entace;result=0";
                    // нажата кнопка войти
                     
                }
                 * */
                // иначе
                answerFromServer = "querry-error";
                 
                




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
