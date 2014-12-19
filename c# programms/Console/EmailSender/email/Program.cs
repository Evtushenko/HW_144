using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Mail;
using System.Net;
using System.Net.Mime;

namespace email
{
    class Program
    {
        private static MailMessage mail;
        private static void addFile(string file)
        {
            Attachment data = new Attachment(file, MediaTypeNames.Application.Octet);
            ContentDisposition disposition = data.ContentDisposition;
            disposition.CreationDate = System.IO.File.GetCreationTime(file);
            disposition.ModificationDate = System.IO.File.GetLastWriteTime(file);
            disposition.ReadDate = System.IO.File.GetLastAccessTime(file);
            mail.Attachments.Add(data);
        }

        private static void sendEmailTo(string mailto, string message) {
                string smtpServer = "smtp.gmail.com";
                string from = "starson4587@gmail.com";
                string password = "djkoolherc";
                string caption = "Письмо для " + mailto;
                try
                {
                    mail = new MailMessage();
                    mail.From = new MailAddress(from);
                    mail.To.Add(new MailAddress(mailto));
                    mail.Subject = caption;
                    mail.Body = message;

                    var txtFiles = Directory.EnumerateFiles("files", "*.txt");
                    foreach (string file_path in txtFiles)
                    {
                        addFile(file_path);
                    }
                    var logFiles = Directory.EnumerateFiles("files", "*.log");
                    foreach (string file_path in logFiles)
                    {
                        addFile(file_path);
                    }
                    SmtpClient client = new SmtpClient();
                    client.Host = smtpServer;
                    client.Port = 587;
                    client.EnableSsl = true;
                    client.Credentials = new NetworkCredential(from.Split('@')[0], password);
                    client.DeliveryMethod = SmtpDeliveryMethod.Network;
                    client.Send(mail);
                    mail.Dispose();
                    Console.WriteLine("Successfully sent to " + mailto);
                }
                catch (Exception e)
                {
                    throw new Exception("Mail.Send: " + e.Message);
                }
        }

        static void Main(string[] args)
        {     
            Console.WriteLine("email sender! First arg - email adress second - Your message inside \"\"");
            if (args.Length > 0)
            {    
                sendEmailTo(args[0], args[1]);
            }
            else
            {
                Console.WriteLine("zero arg");
            }
        }
    }
}
