using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;

namespace _134_File_StreamWriteReader
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fsWrite = new FileStream("a.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsWrite);

            sw.Write("Hello World");
            sw.WriteLine(" Line ");
            sw.WriteLine(" Line ");
            sw.Write(" Close ");

            sw.Close();

            //읽기
            FileStream fsRead = File.Open("a.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fsRead);

            Console.WriteLine("sr.BaseStream.Length: " + sr.BaseStream.Length);

            while(false == sr.EndOfStream)
            {
                Console.WriteLine(sr.ReadLine());
            }

            sr.Close();

            //stramWriter, streamReader 단독 사용
            StreamWriter streamWriter = new StreamWriter("b.txt");

            streamWriter.WriteLine("A");
            streamWriter.WriteLine("B");
            streamWriter.WriteLine("C");
            streamWriter.WriteLine("D");

            streamWriter.Close();

            StreamReader streamReader = new StreamReader("b.txt");

            while(false == streamReader.EndOfStream)
            {
                Console.WriteLine(streamReader.ReadLine());
            }

            streamReader.Close();
        }
    }
}
