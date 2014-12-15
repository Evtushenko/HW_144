/*
        * Общее описание
 *  Задача и сравнении параллельного и последовательного вычислений, которые формально описаны в файлах.
 Программа сначала генерирует 10 файлов, по 1000 000 операций в каждом, аргументы тоже рандомные.
 Затем проиходит последовательнное и параллельное вычисление. Выводятся их результаты для каждого файла и общее время на 10 файлов.
 
        * структура класса Program
 * private static void AddText(FileStream fs, string value) - добавляет строку в указанный файл
 * public void  generateFiles() - генерирует 10 файлов со случайными данными
 * public void calcSequence() - последовательное вычисление и вывод на экран
 * public void calcByIndex(int i, ref double[] results) - вспомогательная функция - вычилсение для одноного файла по индексу
 * public void calcParallel() - параллельное вычисление и вывод на экран
 
        * Формальный язык:
 * init(x) - инициализировать начальное значение
 * sum(x)  - прибавить 
 * suв(x)  - вычесть
 * mul(x)  - умножить
 * div(x)  - разделить
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.IO;
using System.Threading;
using System.Diagnostics;

namespace Параллельное_чтение_файлов
{
    
    class Program
    {
        const int amount_files = 10;
        const int amount_strings = 1000000;

        private static void AddText(FileStream fs, string value)
        {
            byte[] info = new UTF8Encoding(true).GetBytes(value);
            fs.Write(info, 0, info.Length);
        }

        public void  generateFiles() {
            // Функции формального языка:
            // init(x) - инициализировать начальное значение
            // sum(x)  - прибавить 
            // sub(x)  - отнять
            // mul(x)  - умножить
            // div(x)  - разделить
            List<string> all_function = new List<string>();
            all_function.Add("init");
            all_function.Add("sum");
            all_function.Add("sub");
            all_function.Add("mul");
            all_function.Add("div");

            Random rand = new Random();

            // создаем файлы
            for (int i = 0; i < amount_files; i++)
            {
                string file_name = i.ToString() + ".txt";
                FileStream file = File.Create(file_name);
                AddText(file, all_function[0]+"("+i.ToString()+");\n");
                for (int j = 0; j < amount_strings; j++)
                {
                    int index = rand.Next() % 6;
                    int a = rand.Next() % 10 + 1;
                    if (index == 0 || index == 1)
                    {
                        AddText(file, all_function[1] + "(" + a.ToString() + ");\n");
                    }
                    else
                    {
                        if (index == 2 || index == 3)
                            AddText(file, all_function[2] + "(" + a.ToString() + ");\n");
                        else
                            if (index == 4)
                            {
                                AddText(file, all_function[3] + "(" +a.ToString()+");\n");
                            }
                            else
                            {
                                AddText(file, all_function[4] + "(" + a.ToString() + ");\n");
                            }
                    }

                }
                    file.Close();
            }
        }

        public void calcSequence()
        {
            // мерим время
            Stopwatch watch = new Stopwatch();
            watch.Start();

            double[] results = new double[10];
            for (int i = 0; i < 10; i++)
            {
                calcByIndex(i, ref results);
            }
            Console.WriteLine("sequence result:");
            foreach (double res in results)
            {
                Console.WriteLine(res);
            }

            watch.Stop();
            // Get the elapsed time as a TimeSpan value.
            TimeSpan ts = watch.Elapsed;
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
            ts.Hours, ts.Minutes, ts.Seconds,
            ts.Milliseconds / 10);
            Console.WriteLine("RunTime " + elapsedTime);

        }

        // метод, который принимает

        public void calcByIndex(int i, ref double[] results)
        {
            {
                string line;
                System.IO.StreamReader file =
                    new System.IO.StreamReader(@i.ToString() + ".txt");

                double current_result = 1;
                while ((line = file.ReadLine()) != null)
                {
                    if (line.Length > 0)
                    {

                        string function_name = line.Split('(')[0];
                        double argument = Convert.ToDouble((line.Split('(')[1]).Split(')')[0]);
                        switch (function_name)
                        {
                            case "init":
                                current_result = argument;
                                break;
                            case "sum":
                                current_result += argument;
                                break;
                            case "sub":
                                current_result -= argument;
                                break;
                            case "mul":
                                current_result *= argument;
                                break;
                            case "div":
                                current_result /= argument;
                                break;
                        }

                        if (current_result > 100000 || current_result < 0.0001)
                            current_result = 1;

                    }
                }
                file.Close();
                results[i] = current_result;
            }
        }

        public void calcParallel()
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();
            double[] results = new double[10];

            const int must_be_read = 10;
            int already_read = 0;
            Parallel.For(0, must_be_read, (i, loopState) =>
            {
                
                Interlocked.Increment(ref already_read);
                calcByIndex(i, ref results);
                if (already_read == 10)
                {
                    loopState.Stop();
                }
            });

            watch.Stop();
            Console.WriteLine("parallel result:");
            foreach (double res in results)
            {
                Console.WriteLine(res);
            }
            // Get the elapsed time as a TimeSpan value.
            TimeSpan ts = watch.Elapsed;
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
            ts.Hours, ts.Minutes, ts.Seconds,
            ts.Milliseconds / 10);
            Console.WriteLine("RunTime " + elapsedTime);
        }

        static void Main(string[] args)
        {

            Program a = new Program();
            // создали 10 рандомных файлов по 1000 операций в каждом. Станадарт операций описан выше.
            a.generateFiles();
            // последовательно вычислили
            a.calcSequence();
            // Параллельно вычислили
            a.calcParallel();
        }
    }
}
